#ifndef __PAGING_CAPACITY__
#define __PAGING_CAPACITY__


namespace PAGING
{
	class eNB
	{
	public:
		eNB(int BW, int cfg_nB);

		void set_Paging_Param(int paging_second);
		void start_simulate();


	private:
		double pr_n(int n,double lamida);
		bool paging_param;
		int n_rb;
		int max_record_po;
		double po_radioframe; /*   nB div T*/
		int paging_rate;  //average paging number per radio frame
		int nB;
		int paging_N;
		int paging_cycle;
		int queue_num;
		int queue[100000][10000];  //assume a 1000000 queue capacity memory for 10000 radio frame




	};
}

#endif // !__PAGING_CAPACITY__
