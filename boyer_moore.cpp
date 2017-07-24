/*************************************************************************
	> File Name: boyer_moore.cpp
	> Author: CHF
	> Mail: haifeng.cai@youhualin.com 
	> Created Time: 2017年07月23日 星期日 15时56分48秒
 ************************************************************************/

#include <iostream>
#include <boost/algorithm/searching/boyer_moore.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>
#include <boost/algorithm/searching/boyer_moore_horspool.hpp>
using namespace std;


int main()
{
    string strHaystack = "111223 shiahidf a hallo hellow";
    string strNeedle = "hello";

    string::iterator it = boost::algorithm::boyer_moore_search(strHaystack.begin(), strHaystack.end(), strNeedle.begin(), strNeedle.end());
    if (it != strHaystack.end()) {
        cout<<"find the substring in haystack: "<<*it<<endl;
    }

    string::iterator it_temp = boost::algorithm::boyer_moore_horspool_search(strHaystack.begin(), strHaystack.end(), strNeedle.begin(), strNeedle.end());
    if (it_temp != strHaystack.end()) {
        cout<<"boyer_moore_horspool_search find it_temp"<<endl;
    }

    string::iterator it_kmp = boost::algorithm::knuth_morris_pratt_search(strHaystack.begin(), strHaystack.end(), strNeedle.begin(), strNeedle.end());
    if (it_kmp != strHaystack.end()) {
        cout<<"boyer_moore_horspool_search find it_kmp"<<endl;
    }


	return 0;
}

