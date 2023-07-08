//
// Created by DSP on 2023/7/4.
//

#include "product.h"

using namespace std;
void product::setSelf(string n){
    productNum=n;
    filename = n+".csv";
    //以读入方式打开文件
    ifstream csv_data(filename, ios::in);

    if (!csv_data.is_open())
    {
        cout << "输入错误！没有此商品。" << endl;
        exit(1);
    }
    else {
        string line;

        vector<string> words;
        string word;
        istringstream sin;
        getline(csv_data, line);
            // 清空vector及字符串流,只存当前行的数据
            //words.clear();
            //sin.clear();
            sin.str(line);
            //将字符串流sin中的字符读到字符串数组words中，以逗号为分隔符
            while (getline(sin, word, ','))
            {
                //cout << word << endl;
                words.push_back(word); //将每一格中的数据逐个push
                std::cout << word<<endl;
            }
        name=words[0];
        sellingPrice=stof(words[1]);
        purchasePrice=stof(words[2]);
        repertory= stof(words[3]);
        refundable=stoi(words[4]);
        csv_data.close();
    }
}
void sellingProduct::sell(float number) {
    //repertory-=number;
    float pay=number*sellingPrice;
    cout<<"售价为"<<sellingPrice<<"购买"<<number<<"单位，应付"<<pay<<endl;
    cout<<"N 顾客取消购买             Y 顾客确认购买"<<endl;
    char temp;
    cin>>temp;
    if(temp=='Y'){
        sellNum+=1;
        sellMoney+=pay;
        time_t now = time(NULL);
        tm* tm_t = localtime(&now);
        std::stringstream ss;
        ss << tm_t->tm_year + 1900 << " " << tm_t->tm_mon + 1 << " " << tm_t->tm_mday
           << " " << tm_t->tm_hour << " " << tm_t->tm_min << " " << tm_t->tm_sec;
        repertory-=number;
        cout<<"余量:"<<repertory<<endl;
        rewind(stdin);
        getchar();
        doneRecord="售出 "+productNum+"."+name+",单位 "+to_string(number)+",总额 "+to_string(pay)+",时间 "+ss.str();
        ofstream outFile;
        outFile.open(record, ios::app); // 打开模式可省略
        outFile<<doneRecord<<endl;
        outFile.close();
        outFile.open(filename, ios::trunc); // 打开模式可省略
        outFile<<name<<","<<sellingPrice<<","<<purchasePrice<<","<<repertory<<","<<refundable<<endl;
        outFile.close();
    }
    else{
        return;
    }
}
void purchasingProduct::purchase(float number) {
    //repertory+=number;
    float pay=number*purchasePrice;
    cout<<"售价为"<<purchasePrice<<"购买"<<number<<"单位，应付"<<pay<<endl;
    cout<<"N 店家取消购入             Y 店家确认购买"<<endl;
    char temp;
    cin>>temp;
    if(temp=='Y'){
        purchaseNum+=1;
        purchaseMoney+=pay;
        time_t now = time(NULL);
        tm* tm_t = localtime(&now);
        std::stringstream ss;
        ss << tm_t->tm_year + 1900 << " " << tm_t->tm_mon + 1 << " " << tm_t->tm_mday
           << " " << tm_t->tm_hour << " " << tm_t->tm_min << " " << tm_t->tm_sec;
        repertory+=number;
        cout<<"余量:"<<repertory<<endl;
        rewind(stdin);
        getchar();
        doneRecord="购入 "+productNum+"."+name+",单位 "+to_string(number)+",总额 "+to_string(pay)+",时间 "+ss.str();
        ofstream outFile;
        outFile.open(record, ios::app); // 打开模式可省略
        outFile<<doneRecord<<endl;
        outFile.close();
        outFile.open(filename, ios::trunc); // 打开模式可省略
        outFile<<name<<","<<sellingPrice<<","<<purchasePrice<<","<<repertory<<","<<refundable<<endl;
        outFile.close();
    }
    else{
        return;
    }
}
product::product() {
    repertory=0;
    sellingPrice=0;
    name=" ";
    purchasePrice=0;
    refundable=0;
    refundMoney=0;
    refundNum=0;
    sellMoney=0;
    sellNum=0;
    purchaseMoney=0;
    purchaseNum=0;
}
void refundProduct::refund(float number) {
    if(refundable!=true){
        cout<<"该商品不可退还！"<<endl;
        rewind(stdin);
        getchar();
        return;
    }
    //repertory+=number;
    float pay=number*sellingPrice;
    cout<<"售价为"<<sellingPrice<<"退款"<<number<<"单位，应付"<<pay<<endl;
    cout<<"N 客户取消退货             Y 客户确认退货"<<endl;
    char temp;
    cin>>temp;
    if(temp=='Y'){
        refundNum+=1;
        refundMoney+=pay;

        time_t now = time(NULL);
        tm* tm_t = localtime(&now);
        std::stringstream ss;
        ss << tm_t->tm_year + 1900 << " " << tm_t->tm_mon + 1 << " " << tm_t->tm_mday
           << " " << tm_t->tm_hour << " " << tm_t->tm_min << " " << tm_t->tm_sec;
        //std::cout << ss.str();
        repertory+=number;
        cout<<"余量:"<<repertory<<endl;
        rewind(stdin);
        getchar();
        doneRecord="退货 "+productNum+"."+name+",单位 "+to_string(number)+",总额 "+to_string(pay)+",时间 "+ss.str();
        ofstream outFile;
        outFile.open(record, ios::app); // 打开模式可省略
        outFile<<doneRecord<<endl;
        outFile.close();
        outFile.open(filename, ios::trunc); // 打开模式可省略
        outFile<<name<<","<<sellingPrice<<","<<purchasePrice<<","<<repertory<<","<<refundable<<endl;
        outFile.close();
    }
    else{
        return;
    }
}
product::~product() {
    time_t now = time(NULL);
    tm* tm_t = localtime(&now);
    std::stringstream ss;
    ss << tm_t->tm_year + 1900 << " " << tm_t->tm_mon + 1 << " " << tm_t->tm_mday
       << " " << tm_t->tm_hour << " " << tm_t->tm_min << " " << tm_t->tm_sec;
    ofstream outFile;
    outFile.open(dailyRecord, ios::app); // 打开模式可省略
    outFile<<sellNum<<","<<sellMoney<<","<<purchaseNum<<","<<purchaseMoney<<","<<refundNum<<","<<refundMoney<<","<<ss.str()<<endl;
    outFile.close();
}
//void showDetail(product *myProduct){
    //cout<<"商品名称:"<<myProduct->name<<" 售价:"<<myProduct->sellingPrice<<" 进价:"<<myProduct->purchasePrice<<" 存量:"<<myProduct->repertory<<" 是否可退还:"<<myProduct->refundable<<endl;
//}
void showDeatil(product *myProduct,product*myPurchasingProduct,product* mySellingProduct,product*myRefundProduct) {
    cout<<"商品名称:"<<myProduct->name<<" 售价:"<<myProduct->sellingPrice<<" 进价:"<<myProduct->purchasePrice<<" 存量:"<<myProduct->repertory<<" 是否可退还:"<<myProduct->refundable<<endl;
    cout<<"进货次数:"<<myPurchasingProduct->purchaseNum<<" 交易额:"<<myPurchasingProduct->purchaseMoney<<" 售卖次数:"<<mySellingProduct->sellNum<<" 交易额:"<<mySellingProduct->sellMoney<<" 退货次数:"<<myRefundProduct->refundNum<<" 交易额:"<<myRefundProduct->refundMoney<<endl;
}
void showDetail(int m){
    ifstream csv_data(to_string(m)+".csv", ios::in);
    if (!csv_data.is_open())
    {
        cout << "输入错误！没有此商品。" << endl;
        exit(1);
    }
    else {
        string line;

        vector<string> words;
        string word;
        istringstream sin;
        getline(csv_data, line);
        // 清空vector及字符串流,只存当前行的数据
        //words.clear();
        //sin.clear();
        sin.str(line);
        //将字符串流sin中的字符读到字符串数组words中，以逗号为分隔符
        while (getline(sin, word, ','))
        {
            //cout << word << endl;
            words.push_back(word); //将每一格中的数据逐个push
            std::cout << word<<endl;
        }
        csv_data.close();
    }
}
