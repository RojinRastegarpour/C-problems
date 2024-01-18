#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <assert.h>
using namespace std ;
class Ticket
{
	public: 
	string name;
	int number;
};
	


class Ticket_Manager
{
	public:
    
    bool cancel( int Number )
    {
      for(auto it = TICKET.begin() ; it != TICKET.end() ; it++)
	  {
	  	if(Number == it->number){
	  	TICKET.erase(it);
      		return true ;
		  }
       }
        return false ;
    }
	bool cancel( string Name )
	{ 
	  for(auto it = TICKET.begin() ; it != TICKET.end() ; it++)
	  {
	  	if(Name == it->name){
	  		TICKET.erase(it);
      		return true ;
		  }
	  }
	  return false ;

    }
    
    bool check( string Name )
	{
      for(int i=0; i<TICKET.size(); i++)
	  {
      	if(Name == TICKET[i].name){
      		return true ;
		  }
		 
	  }
       return false ;
    }
    
    bool check( int Number )
	{
		 for(int i=0; i<TICKET.size(); i++)
		 {
      	    if(Number == TICKET[i].number){
      		return true ;
		  }
    }
    return false ;
	}
    bool reserve( int Number , string Name )
	{ 
	  Ticket T;
	  T.name = Name;
	  T.number = Number;
	  if(check(Number)){
	  	 return false ;
	  }
	  if(check(Name)){
	  	 cancel(Name);
	  }
	  	 TICKET.push_back(T);
	     return true ;
    }

    void show_ticket()
    {
      for(auto it = TICKET.begin() ; it != TICKET.end() ; it++)
          {
          	cout<< it->number <<" ";
			  cout << it->name<< endl;
		  }
    }   
  private:  
  vector<Ticket> TICKET;
  
};
bool if_string(string str)
{
	assert(str.size() > 0);
	return isalpha(str[0]);
}

int main()
{
	int n;
	string str1 , str2 ,dastoor ;
	Ticket_Manager rojin;
	cin >> n ; 
	for(int i=0 ; i<n ; i++)
	{
	  string s;
	  int num;
	  cin>> dastoor;
	  if( dastoor == "reserve" ){
	   cin>> str1 >> str2;
	   
	   if(if_string(str1)){
	      s = str1;
	      num = stoi(str2);
	   }else{
	      s = str2;
	   	  num = stoi(str1);
	   } 
	   
       if(rojin.reserve(num , s)){
       	
       	cout<< "done"<<endl;
	   }else{
	   	
	   	cout<<"seat not available"<<endl;
	   }
    }
	   else if(dastoor == "check"){  
	   
		    cin>> str1 ;
		    if(if_string(str1)){
		    	
		     if(rojin.check(str1)){
		     	cout<< "yes"<<endl;
			 }else{
			 	cout<<"no"<<endl;
			 }
		     
			}else{
				
			 num = stoi(str1);	
		     if(rojin.check(num)){
		     	cout<< "yes"<<endl;
			 }else{
			 	cout<<"no"<<endl;
			 }
			}
		   
		 }else if(dastoor == "cancel"){
		 	
		 	cin>> str1;
		    if(if_string(str1)){
		    	
		       if(rojin.cancel(str1)){ 
		     	   cout<<"done"<<endl;
			    }else{
			 	cout<<"ticket not found"<<endl;
			 }
		     
			}else{
				
			 num = stoi(str1);	
		     if(rojin.cancel(num)){ 
		     	   cout<<"done"<<endl;
			    }else{
			 	cout<<"ticket not found"<<endl;
			}
		   
		   }}else{
		   	
		   	throw runtime_error("dastoor eshtebahee!!");
		   }
		 
        }
        
          rojin.show_ticket();
        
        return 0;
	}
	
    
