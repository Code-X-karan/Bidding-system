#include<iostream>
#include<fstream>
using namespace std;
class details
{ 
   public:
   string name,gender_selection,winner_opponent="Jennifer";//this class will take basic details of user
   string currency="million",space="  ",next_line="\n\n";
   
   int gender_input;
   void perosnal_data()
   {
    cout<<"Please enter your name [Only first name is valid]: ";
    cin>>name;
    starting_point1://if gender is wrong it will comeback at that point 
    cout<<"Please select your gender\n";
    cout<<"(1) Male\n";
    cout<<"(2) Female\n";
    cout<<"Enter here: ";
    cin>>gender_input;
    if(gender_input==1)
    {
      gender_selection="Male";
      cout<<"\n~~ Welcome MR "<<name<<" on auction ~~\n";
    }
    else if(gender_input==2)
    {
      gender_selection="Female";
      cout<<"\n ~~ Welcome Ms "<<name<<" on auction ~~\n";
    }
    else
    {
      cout<<"INVALID ATTEMPT\n\n";
      goto starting_point1;
    }
   }
};
class win_or_lose_logic:public details //in this class logic is defined that user win or not
{
  
  public:
  float bid_input_by_user;
  void winner()
  {
    cout<<"\n"<<name<<":"<<bid_input_by_user;
    cout<<"\nJake: "<<bid_input_by_user-(bid_input_by_user*0.25);
    cout<<"\nJennifer: "<<bid_input_by_user-(bid_input_by_user*0.47);
    cout<<"\nPaul: "<<bid_input_by_user-(bid_input_by_user*0.37);
    cout<<"\n\n~~~~ congrats "<<name<<" you win ~~~~\n\n";
    cout<<"The item sold to "<<name<<" in "<<bid_input_by_user<<" million $";

  }
  void loose()
  {
    cout<<"\n"<<name<<":"<<bid_input_by_user;
    cout<<"\nJake: "<<bid_input_by_user-(bid_input_by_user*0.25);
    cout<<"\nJennifer: "<<bid_input_by_user+(bid_input_by_user*0.47);
    cout<<"\nPaul: "<<bid_input_by_user+(bid_input_by_user*0.37);
    cout<<"\n\nYou loose\n\n";
    cout<<"The item sold to jennifer in "<<bid_input_by_user+(bid_input_by_user*0.47)<<" in million $";
  }

};
class bid_on_auction:public win_or_lose_logic
{
public:
int input_item;//this will take input of item that user want to bid
void items()
{ 
   int minimum_bid_amount[6];//it store minimum bidding amount of each item
   cout<<"Select an item from below\n";
   cout<<"(1) Item no 1 (?) [Bidding start from 100 million $]\n";
   cout<<"(2) Item no 2 (?) [Bidding start from 200 million $]\n";
   cout<<"(3) Item no 3 (?) [Bidding start from 300 million $]\n";
   cout<<"(4) Item no 4 (?) [Bidding start from 400 million $]\n";
   cout<<"(5) Item no 5 (?) [Bidding start from 500 million $]\n";
   starting_point2://if user input invalid number it take at back at this point
   cout<<"Enter here: ";
   cin>>input_item;
   if(input_item==1)
   {
      cout<<"\n***The item is 2000 years cleopatra crown***\n\n";
      cout<<"Bidding starts from 100 million $ \n";
      minimum_bid_amount[0]=100;
      cout<<"Enter how much you want to bid: ";
      cin>>bid_input_by_user;
      if(bid_input_by_user<minimum_bid_amount[0])
      {
       cout<<"You are disqualified";
       exit(0);
      }
      else
      {
       winner();
      }
      

   }
   else if(input_item==2)
   {
      cout<<"\n***The item is 1500 year old ancient scrab bettle coin***\n\n";
      cout<<"Bidding starts from 200 million $ \n";
       minimum_bid_amount[1]=200;
      cout<<"Enter how much you want to bid: ";
      cin>>bid_input_by_user;
      if(bid_input_by_user<minimum_bid_amount[1])
      {
       cout<<"You are disqualified";
       exit(0);
      }
      else
      {
        loose();
      }
   }
   else if(input_item==3)
   {
      cout<<"\n***The item is salvator mundi painting by leonardo da vinci***\n\n";
      cout<<"Bidding starts from 300 million $ \n";
      cout<<"Enter how much you want to bid: ";
      cin>>bid_input_by_user;
       minimum_bid_amount[2]=300;
       if(bid_input_by_user<minimum_bid_amount[2])
      {
       cout<<"You are disqualified";
       exit(0);
      }
      else
      {
        loose();
      }
   }
   else if(input_item==4)
   {
      cout<<"\n***The item is glass harmonica by benjamin franklin***\n\n";
      cout<<"Bidding starts from 400 million $ \n";
      cout<<"Enter how much you want to bid: ";
      cin>>bid_input_by_user;
       minimum_bid_amount[3]=400;
       if(bid_input_by_user<minimum_bid_amount[3])
      {
       cout<<"You are disqualified";
       exit(0);
      }
      else
      {
        winner();
      }
   }
   else if(input_item==5)
   {
      cout<<"\n***The item is warren buffett autograph cadillac***\n\n";
      cout<<"Bidding starts from 500 million $ \n";
      cout<<"Enter how much you want to bid: ";
      cin>>bid_input_by_user;
       minimum_bid_amount[4]=500;
       if(bid_input_by_user<minimum_bid_amount[4])
      {
       cout<<"You are disqualified";
       exit(0);
      }
      else
      {
        loose();
      }
   }
   else
   {
      cout<<"INVALID ATTEMPT\n\n";
      goto starting_point2;//it goes to line 48
   }
}
};
class save_data:public bid_on_auction
{
   public:
   void bid_data()
   {
     ofstream bid_file;
     bid_file.open("Bid_data.txt",ios::app);
     if(input_item==1||input_item==4)
     {
      bid_file<<name<<space<<bid_input_by_user<< currency<<space<<input_item<<next_line; 
     }
     else
     {
      bid_file<<winner_opponent<<space<<bid_input_by_user+(bid_input_by_user*0.47)<< currency<<space<<input_item<<next_line;
     }
    bid_file.close();
   }
};

int main()
{   
   int choice;
   cout<<" ____________________________________________________________\n";  //line 6 to line 13 only m
   cout<<"|    ****** WELCOME TO J_S ONLINE AUCTION SYSTEM ******      |\n";
   cout<<"|____________________________________________________________|\n\n\n";   
      save_data bid_on_auction_called;
      bid_on_auction_called.perosnal_data();
      cout<<"\n";
      bid_on_auction_called.items();
      bid_on_auction_called.bid_data();
      return 0;
 
}