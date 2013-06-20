#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
#include "PAGING.h"

using namespace PAGING;

eNB::eNB(int BW, int cfg_nB)
{
	switch (BW)
	{
	case 5:
		n_rb = 25;
		max_record_po = 7;
		break;
	case 10:
		n_rb = 50;
		max_record_po = 16;
		break;
	case 15:
		n_rb = 75;
		max_record_po = 7;
		break;
	case 20:
		n_rb = 100;
		max_record_po = 7;
		break;
	default:
		paging_param = false;
		break;
	}
	paging_cycle = 128;
	nB = cfg_nB * paging_cycle;
	po_radioframe = nB/double(paging_cycle);
	paging_N = paging_cycle>nB?nB:paging_cycle;

	for (int i =0; i<100000; i++)
		for (int j = 0; j<10000;j++)
			queue[i][j] = 0;
	queue_num = 0;		
}

double eNB::pr_n(int n, double lamida)
{
	int sum = 0;
	if (n == 0)
		return exp(-1*lamida);
	else
	{
		return lamida/n*pr_n(n-1, lamida);
	}
	
}

void eNB::set_Paging_Param(int paging_second)
{
	paging_rate = paging_second * 100;
}
void eNB::start_simulate()
{
	int rand_seed = (unsigned int)time(NULL);
	srand(rand_seed);
	for (int sfn = 0; sfn < 1024; sfn++)
	{
		int prn = rand() % 100;
		int paging_num = 0;
		while (prn > 100*pr_n(paging_num, paging_rate))
		{
			prn -= 100*pr_n(paging_num,paging_rate);
			paging_num++;
			int ue_id = rand() % 1024;

			paging_cycle/paging_N*(ue_id % paging_N);
		}

	}

}