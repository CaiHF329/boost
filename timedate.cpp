/*************************************************************************
	> File Name: timedate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月21日 星期一 11时39分33秒
 ************************************************************************/

/*
*compile cmd: g++ xxx.cpp -o xxx -lboost_date_time
*
*/
#include<iostream>

#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/c_time.hpp>
#include <boost/date_time/date_clock_device.hpp>

using namespace std;

/*
* date_time 
*
* */
void dateconstruct()
{
    boost::gregorian::date d1(2002, 10, 10);
    cout<<d1<<endl;

    boost::gregorian::date d2 = d1;
    cout<<"copy construction: "<<d2<<endl;

    boost::gregorian::date d3;
    cout<<"NILL construct: "<<d3<<endl;

}

void constructfromstring()
{
    std::string ds("2017/8/22");
    boost::gregorian::date d1 = boost::gregorian::from_string(ds);
    cout<<"d1: "<<d1<<endl;

    std::string ds2 = "20170605";
    boost::gregorian::date d2 = boost::gregorian::from_undelimited_string(ds2);
    cout<<"d2: "<<d2<<endl;
}

void constructfromclock()
{
    boost::gregorian::date localday = boost::gregorian::day_clock::local_day();
    cout<<"local_day(): "<<localday<<endl;

    boost::gregorian::date universalday(boost::gregorian::day_clock::universal_day());
    cout<<"universal_day(): "<<universalday<<endl;

}

void memberFunctionOfDate()
{
    //to get a date 
    boost::gregorian::date d1(boost::gregorian::from_string("2017/10/10"));
    cout<<"================\ndate: "<<d1<<endl;
    cout<<"Year: "<<d1.year()<<endl;
    boost::gregorian::greg_month month = d1.month();
    cout<<"Month: "<<month<<endl;
    cout<<"Day: "<<d1.day()<<endl;

    boost::gregorian::date::ymd_type ymd = d1.year_month_day();
    cout<<"year_month_day(): "<<ymd.year<<" "<<ymd.month<<" "<<ymd.day<<endl;
    
    cout<<"day_of_week(): "<<d1.day_of_week()<<endl;

    cout<<"day_of_year(): "<<d1.day_of_year()<<endl;

    cout<<"is_infinity(): "<<d1.is_infinity()<<endl;//ri qi wei wuxian riqi 

    cout<<"is_neg_infinity(): "<<d1.is_neg_infinity()<<endl;

    cout<<"is_special(): "<<d1.is_special()<<endl;
}

void operator1()
{
    boost::gregorian::date d1(2017, 10, 10);
    boost::gregorian::date d2(2017, 10, 12);
    cout<<"d1 = d2: "<<(d1 == d2)<<endl;
    d2 = d1 + boost::gregorian::date_duration(25);
    cout<<d2<<endl;

    d2 = d2 - boost::gregorian::date_duration(100);
    cout<<d2<<endl;
}

void tm_function()
{
    boost::gregorian::date d1(2017, 06, 20);
    cout<<d1<<endl;
}

void date_duration_class()
{
    boost::gregorian::date_duration dd1(10);
    cout<<"dd1: "<<dd1<<endl;
    boost::gregorian::days day1(boost::gregorian::neg_infin);
    //boost::gregorian::days day1(10000000000000000);
    boost::gregorian::days day2(100);
    cout<<"day1: "<<day1<<", day2: "<<day2<<endl;
    
    cout<<"=============================\n";
    cout<<dd1.days()<<endl;

    boost::gregorian::date_duration dd2(-1);
    dd1 = dd2;
    cout<<dd1.is_negative()<<endl;
    cout<<dd1.is_special()<<endl;

}

int main()
{
    dateconstruct();

    constructfromstring();

    constructfromclock();

    memberFunctionOfDate();

    operator1();

    date_duration_class();

    return 0;
}
