#include <iostream>
#include"product.h"
using namespace std;
void inquire(product*,product*,product*,product*);
void whoseKid();
int main() {
    int oldTemp;
    int& temp=oldTemp;
    string productNum;//货号
    float sellNum;//销售量
    product* currentProduct;
    sellingProduct mySellingProduct;
    purchasingProduct myPurchasingProduct;
    refundProduct myRefundProduct;
    float purchaseNum;//买入量
    float refundNum;//退货量
    cout << "欢迎使用荣杰商品交易系统" << endl;
    cout << "1.批发购入" << endl;
    cout << "2.商品结算" << endl;
    cout << "3.退货管理" << endl;
    cout << "4.信息查询" << endl;
    cout << "5.退出" << endl;
    cin >> temp;
    system("cls");
    while (temp != 5)
    {

        switch (temp) {
            case 1:
                cout << "输入商品编号" << endl;
                cin>>productNum;
                myPurchasingProduct.setSelf(productNum);
                cout << "输入购买数量" << endl;
                cin>>purchaseNum;
                myPurchasingProduct.purchase(purchaseNum);
                currentProduct=&myPurchasingProduct;
                system("cls");
                break;
            case 2:
                cout << "输入商品编号" << endl;
                cin>>productNum;
                mySellingProduct.setSelf(productNum);
                cout << "输入购买数量" << endl;
                cin>>sellNum;
                mySellingProduct.sell(sellNum);
                currentProduct=&mySellingProduct;
                system("cls");
                break;
            case 3:
                cout << "输入商品编号" << endl;
                cin>>productNum;
                myRefundProduct.setSelf(productNum);
                cout << "输入退货数量" << endl;
                cin>>refundNum;
                myRefundProduct.refund(refundNum);
                currentProduct=&myRefundProduct;
                system("cls");
                break;
            case 4:
                inquire(currentProduct,&myPurchasingProduct,&mySellingProduct,&myRefundProduct);
                break;
            default:
                cout << "没有这个选项.\n";
                break;
        }
        cout<<"选择业务"<<endl;
        cout << "1.批发购入" << endl;
        cout << "2.商品结算" << endl;
        cout << "3.退货管理" << endl;
        cout << "4.信息查询" << endl;
        cout << "5.退出" << endl;
        cin>>temp;
        system("cls");
    }
}
void whoseKid(){
    cout<<"谁家小孩？别乱点。"<<endl;
}
void inquire(product*currentProduct,product*myPurchasingProduct,product*mySellingProduct,product*myRefundProduct){
    char a;
    int b;
    cout<<"1.目前商品信息与收支详情"<<endl;
    cout<<"2.商品信息查询"<<endl;
    cout<<"3.退出"<<endl;
    cin>>a;
    if(a=='1'){
        showDeatil(currentProduct,myPurchasingProduct,mySellingProduct,myRefundProduct);
        rewind(stdin);
        getchar();
        system("cls");
    }
    else if(a=='2'){
        cout<<"输入货号"<<endl;
        cin>>b;
        showDetail(b);
        rewind(stdin);
        getchar();
        system("cls");
    }
    else if(a=='3'){
        return ;
    }
    else {
        whoseKid();
        rewind(stdin);
        getchar();
        system("cls");
        return ;
    }
}