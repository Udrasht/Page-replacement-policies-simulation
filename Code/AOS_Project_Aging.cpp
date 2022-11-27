#include <bits/stdc++.h>
using namespace std;
class pageinfo
{
public:
	unsigned int  counter;
    int page_no;
    
    pageinfo(int no)
    {
        page_no=no;
        counter=1<<(31);
    }
};
pair<int,int> aging_implementation(int no_frame,vector<int> &frames_nos){
	int page_hit=0;
	int page_fault=0;
	// cout<<"hello"<<endl;
	//cout<<"\033[0;43m";
	unordered_map<int,pageinfo*> data_map;
	unordered_set<int>frames;
	int len=frames_nos.size();
	for(auto it : frames_nos){
		//no space for new page
		if(frames.size()>=no_frame){
			//page not present in main memory
            if(frames.find(it)==frames.end()){
                     int replaced_page;
                     int min=INT_MAX;
                     for(auto jt : data_map){
                     	
                     	if(jt.second->counter<min){
                     		min=jt.second->counter;
                     		replaced_page=jt.first;
                     	}
                     	jt.second->counter>>=1;
                     }
                     data_map.erase(replaced_page);
                     frames.erase(replaced_page);
                     frames.insert(it);
                     data_map[it]=new pageinfo(it);
                     page_fault=page_fault+1;
                    // cout<<"FAULT "<<"-->";


            }
            else{
            	//page present in main memory
            	for(auto jt : data_map){
            		if(it==jt.first){
            			jt.second->counter>>=1;
            			jt.second->counter=jt.second->counter|1<<(31);
            		}
            		else{
            			jt.second->counter>>=1;
            		}
            	}
            	page_hit=page_hit+1;
            	//cout<<"HIT   "<<"-->";
            }
        }
            else{
            	//page is not present in main memory and frams are available
            	if(frames.find(it)==frames.end()){
            		for(auto jt : data_map){
                     	jt.second->counter>>=1;
                     }
                     page_fault=page_fault+1;
                     frames.insert(it);
                     data_map[it]=new pageinfo(it);
                    // cout<<"FAULT "<<"-->";
            	}
            	else{
            		//page is already present
            		for(auto jt : data_map){
            		if(it==jt.first){
            			jt.second->counter>>=1;
            			jt.second->counter=jt.second->counter|1<<(31);
            		}
            		else{
            			jt.second->counter>>=1;
            		}
            	}
            	page_hit=page_hit+1;
            	//cout<<"HIT   "<<"-->";
            	}

            }
            //for( auto jk : frames){
            //	cout<<jk<<" ";
            //}
           // cout<<endl;
		
	}
	//cout<<"\033[0m";
	//cout<<page_hit<<"  "<<page_fault<<endl;
	return {page_hit,page_fault};
   
}
void string_to_frame_vector(string str,vector<int> &frames_nos){
	int len=str.size();
	string number="";
      
	for(int i=0;i<len;i++){
           if(str[i]==' '){
           	int no=stoi(number);
           	frames_nos.push_back(no);
           	number="";
           }
           else{
           	number=number+str[i];
           }
	}
		int no=stoi(number);
           	frames_nos.push_back(no);

}
int main(){
	  cout<<"\033[0;31m";
	cout<<"**************Aging***************"<<endl;
	cout<<"\033[0m";
	 ifstream inputFile("input.txt");
	 ofstream fout("agingoutput.txt",ios_base::app);
	 //vector<int> framenumber;
	 string str;
	 while(getline(inputFile,str)){
	 	vector<int> frames_nos;
	 	int pagefault=0;
	 	int pagehit=0;
	 	int no_frame=stoi(str);
	 
	 	getline(inputFile,str);
	 	string_to_frame_vector(str,frames_nos);
	 	// for(auto it:frames_nos){
	 	// 	cout<<it<<" ";
	 	// }
	 	// cout<<endl;
	 	//cout<<str<<endl;
	 	getline(inputFile,str);
	 pair<int,int> datacaught=aging_implementation(no_frame,frames_nos);
	 	// cout<<str<<endl;
	 pagehit=datacaught.first;
	 pagefault=datacaught.second;
	 int flen=frames_nos.size();

	 cout<<"Number of frame in MM: "<<no_frame<<endl;
	 cout<<"Number of pages: "<<flen<<endl;
	    cout<<"\033[0;42m";
        cout<<"Number of page hit: ";
         
         cout<<pagehit;
          cout<<"\033[0m";
          cout<<endl;
         cout<<"\033[0;41m";
        cout<<"Number of page fault: ";
        
         
         cout<<pagefault;
          cout<<"\033[0m";
          cout<<endl;
          float hitratio=pagehit*1.0;
          hitratio=hitratio/flen;
          float faultratio=pagefault*1.0;
          faultratio=faultratio/flen;
          cout<<"\033[0;42m";
        cout<<"Page hit ratio : ";
         
         cout<<hitratio;
          cout<<"\033[0m";
          cout<<endl;
           cout<<"\033[0;41m";
        cout<<"Page miss ratio: ";
        
         
         cout<<faultratio;
          cout<<"\033[0m";
          cout<<endl;
          
          fout<<no_frame<<" "<<pagefault<<" "<<pagehit<<" "<<flen<<endl;

          



	


	 }
	 inputFile.close();
	
	 fout.close();
}
