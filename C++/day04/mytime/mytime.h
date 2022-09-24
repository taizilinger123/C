#ifndef MYTIME_H
#define MYTIME_H
    class MyTime{
		private:
		int hour;
		int min;
        int sec;
		public:
		MyTime(int hour=0,int min=0,int sec=0);
		void setTime(int hour=0,int min=0,int sec=0);
		void show();
		void dida();
	};
#endif
