//
// Created by DSP on 2023/7/4.
//

#ifndef SELLINGSYSTEM_PRODUCT_H
#define SELLINGSYSTEM_PRODUCT_H
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class product {
public:
    //void test();
    float sellingPrice;//售价
    float purchasePrice;//买入价
    float repertory=0;//存量
    const string record="收支细目.csv";
    const string dailyRecord="统计总表.csv";
    string filename;//商品信息文件
    string name;//商品名称
    time_t nowtime;//记录时间
    int sellNum=0;//售出次数
    int refundNum=0;//退回次数
    int purchaseNum=0;//采购次数
    float sellMoney=0;//销售总额
    float refundMoney=0;
    float purchaseMoney=0;
    //time(&nowtime); //获取1970年1月1日0点0分0秒到现在经过的秒数
   // tm* p = localtime(&nowtime); //将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以要+1
   // printf("%04d:%02d:%02d %02d:%02d:%02d\n", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
    string productNum;//商品编号
    string doneRecord;//记录
    bool refundable;//是否可以退货
    void setSelf(string);
    //friend void showDetail(product*);
    friend void showDeatil(product*,product*,product*,product*);
    ~product();
    product();
};
class sellingProduct:virtual public product{
public:
    void sell(float);
};
class purchasingProduct:public product{
public:
    void purchase(float);
};
class refundProduct:public product{
public:
    void refund(float);
};
//void showDetail(product*);
void showDetail(int);
void showDeatil(product*,product*,product*,product*);
#endif //SELLINGSYSTEM_PRODUCT_H