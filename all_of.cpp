/*************************************************************************
	> File Name: all_of.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年07月24日 星期一 15时06分10秒
 ************************************************************************/

#include <iostream>
#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>
#include <boost/algorithm/cxx11/none_of.hpp>
#include <vector>
#include <string>
using namespace std;

bool NumberInBounds(int i)
{
    if (i < 30 && i > 0)
    {
        return true;
    }
    return false;
}

bool findstr(string& str)
{
    if (0 == str.compare("555")) {
        return true;
    }
    else {
        return false;
    }
}

bool findint(int i)
{
    if (i == 1909) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int iArray[10] = {5, 9, 15, 30 ,20, 18, 16, 1, 200, 10};

    bool bStatus = boost::algorithm::all_of(iArray, NumberInBounds);
    cout<<"status: "<<bStatus<<endl;

    int iArray1[] = {90, 100, 110, 200};
    bool bEqual = boost::algorithm::all_of_equal(iArray1, 90);
    cout<<"bStatus: "<<bEqual<<endl;

    bool bAnyStatus = boost::algorithm::any_of(iArray, NumberInBounds);
    cout<<"any_of: "<<bAnyStatus<<endl;

    bool bAnyEqualStatus = boost::algorithm::any_of_equal(iArray1, 90);
    cout<<"any_of_equal: "<<bAnyEqualStatus<<endl;

    vector<string> vstr;
    vstr.push_back("111");
    vstr.push_back("222");
    vstr.push_back("333");
    vstr.push_back("444");
    vstr.push_back("555");
    
    vector<int> iInt;
    iInt.push_back(1);
    iInt.push_back(2);
    
    bool bNone_of = boost::algorithm::none_of(vstr.begin(), vstr.end(), findstr);
    cout<<"bNone_of: "<<bNone_of<<endl;

    //bool bNone_of = boost::algorithm::none_of(vstr, "1111");
    //cout<<"bNone_of: "<<bNone_of<<endl;

    bool bNone_of_2 = boost::algorithm::none_of(iArray, iArray + sizeof(iArray)/sizeof(int), findint);
    cout<<"bNone_of_2: "<<bNone_of_2<<endl;

    bool bNoneEqual = boost::algorithm::none_of_equal(vstr, "xs");
    cout<<"bNoneEqual: "<<bNoneEqual<<endl;

    return 0;
}
