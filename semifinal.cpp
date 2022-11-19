//preprocessor directive
#include <iostream>
#include <string>
using namespace std;

//structure declaration
struct Customer {
    int customerNum, itemNum, packagingNum;
    string preferredPackaging, paymentMethod, payment;
    float decart, scan, pack, pay, print, idle, customerQueue;
};

//main function
int main()
{
    int x, i;
    float total = 0;

    cout << "";
    cin >> x;

    struct Customer s[x + 1];

    //loop for user input and computation
    for (i = 0; i < x; i++) {
        s[i].customerNum = i + 1;
        cout << "";
        cin >> s[i].itemNum;
        cout << "";
        cin >> s[i].preferredPackaging;
        cout << "";
        cin >> s[i].packagingNum;
        cout << "";
        cin >> s[i].paymentMethod;
        if(s[i].paymentMethod == "cash"){
            cout << "";
            cin >> s[i].payment;
        }

        //computation
        s[i].decart = s[i].itemNum * 0.5;                                   //decarting time
        s[i].scan = s[i].itemNum * 0.5;                                     //scanning time
        if(s[i].preferredPackaging == "box"){                                //packing time
            s[i].pack = (s[i].itemNum * 0.5) + (s[i].packagingNum * 10);
        } else if(s[i].preferredPackaging == "bag") {
            s[i].pack = (s[i].itemNum * 0.5) + (s[i].packagingNum * 5);
        } else {
            s[i].pack = (s[i].itemNum * 0.5);
        }
        if(s[i].paymentMethod == "cash"){                                    //paying time{
            if(s[i].payment == "e"){
                    s[i].pay = 15;
            } else{
                s[i].pay = 20;
            }
        } else if(s[i].paymentMethod == "digital"){
            s[i].pay = 15;
        } else{
            s[i].pay = 0;
        }
        s[i].print = (s[i].itemNum * 0.3) + 2;                              //receipt printing time
        if(i >= 1){                                                         //idle time
            s[i].idle = 3;
        } else {
            s[i].idle = 0;
        }
        s[i].customerQueue = s[i].decart + s[i].scan + s[i].pack + s[i].pay + s[i].print + s[i].idle; // total costumer queue time
    }

    cout << "\nNo. of Customers: " << x << endl;
    cout << "=========================" << endl;

    //loop for display
    for (i = 0; i < x; i++) {
        cout << "Customer #" << (i + 1) << ": " << endl;
        cout << "No. of Cart Items: " << s[i].itemNum << endl;
        if(s[i].preferredPackaging != "box" && s[i].preferredPackaging != "bag"){
            cout << "Preferred Packaging: Invalid Input!" << endl;
        } else {
            cout << "Preferred Packaging: " << s[i].preferredPackaging << endl;
        }

        if(s[i].preferredPackaging == "box"){
            cout << "Number of " << s[i].preferredPackaging << "es" << ": " << s[i].packagingNum << endl;
        } else if(s[i].preferredPackaging == "bag") {
            cout << "Number of " << s[i].preferredPackaging << "s" << ": " << s[i].packagingNum << endl;
        } else {
            cout << "Number of preferred packaging: " << s[i].packagingNum << endl;
        }

        if(s[i].paymentMethod != "cash" && s[i].paymentMethod != "digital"){
            cout << "Preferred Payment Method: Invalid Input!" << endl;;
        }else if(s[i].payment == "e"){
            cout << "Preferred Payment Method: " << s[i].paymentMethod << "(e)" << endl;
        }else if(s[i].payment == "ne"){
            cout << "Preferred Payment Method: " << s[i].paymentMethod << "(ne)" << endl;
        }else {
            cout << "Preferred Payment Method: " << s[i].paymentMethod << endl;
        }
        cout << "-------------------------" << endl;
        cout << "Total De-Carting Time: " << s[i].decart << endl;
        cout << "Total Scanning Time: " << s[i].scan << endl;
        cout << "Total Packing Time: " << s[i].pack << endl;
        cout << "Total Paying Time: " << s[i].pay << endl;
        cout << "Total Receipt Printing Time: " << s[i].print<< endl;
        cout << "Idle Time: " << s[i].idle << endl;
        cout << "Total Customer-Queue Time: " << s[i].customerQueue << endl;
        cout << "++++++++++++++++++++++++++\n";
        total += s[i].customerQueue;
    }
    cout << "Total Lane Queue Time: " << total << endl;                             //total lane queue time
    return 0;
}
