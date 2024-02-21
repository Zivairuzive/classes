#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

#define WITHDRAW_CHARGE     0.010
#define TRANSFER_CHARGE     0.02
#define MAXDAYTRANSFER      1000
#define INSUFFICIENT        cout << "YOU INSUFFICIENT AMOUNT TO CARRY OUT THIS TRANSACTION!" << endl;
#define ENDLINE             cout<< endl

typedef long double LongDouble;

LongDouble BalanceSufficient(int balance);

class BankAccount {

    public:
        double GetBalance(){
            return balance ;
        }

        void WithDraw(int amount){
            if (amount == 0 ){
                return;
            }
            if (amount > 0 && this->balance > amount){
                LongDouble BalanceRemaining = BalanceSufficient(this->GetBalance());
                if (BalanceRemaining > (double)amount) 
                {
                    this->balance = BalanceRemaining-amount;
                    ENDLINE;
                    cout << "You hae suuccessfully withdrawed " << amount  <<  endl;
                    cout << "Balance remaining is " << balance << endl;
                }
            }
            else INSUFFICIENT
        }
        BankAccount(double balance, string name): balance(balance), name(name){};

        void makePayment(BankAccount &user, double amount){
            double chargeCompliment = this->balance*(1-TRANSFER_CHARGE);
            double charge = amount*TRANSFER_CHARGE;

            if (amount < chargeCompliment){
                // allow transfer to happen 
                user.balance += amount;
                this->balance -= amount + charge;
                // debit the charge to the bank 
                ENDLINE;
                cout << "You have transfered " << amount << " to " << user.name << endl;
                cout << "A charge of " << charge << " has been applied to your account" << endl;
                cout << "Your remaining balance is " << balance << endl;
            }
            if (amount > chargeCompliment)
            INSUFFICIENT

        }
        void Deposit(double amount){
            this->balance+= amount;
            ENDLINE;
            cout  << "Amount " << amount << " has been deposited" << endl;
            cout  << "New balance is now " << this->balance << endl;
        }


    private: 
        double balance;
        string name;

};
enum Options {
        CHECK_BALANCE,
        MAKE_PAYMENT,
        WITHDRAW, 
        DEPOSIT,
    };

void transcation(BankAccount &user, bool trans){
    string OptionChoice[4] = {"Check Balance", "Make Payment", "Withdraw", "Deposit",};

    BankAccount bob(100, "Bob Marley");
   

    int myoption, amount;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(20) << OptionChoice[i] << setw(10) << i <<  setw(10) << endl;;
    }
    
    Options choice;
    cout <<  setw(20);
    cin >> setw(20) >> myoption;

    switch (myoption)
    {
    case CHECK_BALANCE:
        cout <<  setw(25) << "Acount Balance is: " << user.GetBalance() << endl;
        return ;
    
    case MAKE_PAYMENT:
        // make payment
        cout << setw(20) << "Enter amount to pay ";
        cin >> amount;
        // validate amount 
        user.makePayment(bob, amount);
        return;
    
    case WITHDRAW:
        // withdrawal 
        cout << setw(20) << "Enter amount to withdraw ";
        cin >> amount;
        user.WithDraw(amount);
        return;
    
    case DEPOSIT:
        cout << setw(20) << "Enter amount to deposit " ;
        cin >> amount;
        ENDLINE;
        user.Deposit(amount);
        return;

    default:
        cout << setw(20) << "No transcation selected" << endl;
        exit(1);

    };

}


LongDouble BalanceSufficient(int balance){
    return (1-WITHDRAW_CHARGE)*balance;
}

// TODO 
// keep users in a file , load the file on startup
// allow user to input their details 
// check from file is user exists 


int main(int argc, char* argv[]){

    BankAccount zee(1000, "Zivai");
    bool shouldContinueTranscation = true;
    char trans_ ;

    cout << setiosflags(ios::fixed | ios::showpoint | ios::right) << setprecision(2);
    cout << setw(50) << "Welcome to the Skirt Bank" << setw(50) << endl;
    cout <<  setw(54) << "Choose from below how to proceed" << endl;

    do
    {
        transcation(zee, shouldContinueTranscation);
        ENDLINE;
        cout << "Would you like to make another transcation? Y [Yes], N [No]" << endl;
        cin >> trans_ ;
        if ('Y'!= toupper(trans_)){
            shouldContinueTranscation=false;
        }
    }
    while(shouldContinueTranscation);
    
    cout << setw(50)<<"Thank you banking with us !!" << endl;

    return 0;
    }