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
pair<int,int> optimal_implementation(int no_frame,vector<int> &frames_nos){
	int page_hit=0;
	int page_fault=0;
	vector<int> frames;
	int lln=frames_nos.size();
	for(int i=0;i<lln;i++){
		if(find(frames.begin(),frames.end(),frames_nos[i])!=frames.end()){
              page_hit=page_hit+1;
              //cout<<"HIT   "<<"-->";
		}
		else{
			int fs=frames.size();
			if(fs>=no_frame){
				int po=i;
				po=po+1;
				int pos=-2;
				for(int k=0;k<fs;k++){
					int j=i+1;
 					int f=0;

					while(j<lln){
						if(frames[k]==frames_nos[j]){
							if(j>=po){
							po=j;
							pos=k;
							//cout<<frames_nos[i]<<"k"<<pos<<"hi"<<k<<endl;
							f++;
                     
						}
					break;}
						//cout<<"uju"<<endl;
						j++;
					}
					if(j==lln){
						//cout<<k<<"hiii"<<endl;
						pos=k;
						break;
					}
				}
				if(pos==-2){
					pos=0;
				}
               //cout<<pos<<endl;
				frames[pos]=frames_nos[i];
				//frames.push_back(it);
				page_fault=page_fault+1;
				//cout<<"FAULT "<<"-->";

			}
			else{
				frames.push_back(frames_nos[i]);
				page_fault=page_fault+1;
				//cout<<"FAULT "<<"-->";

			}
		}
		//for( auto jk : frames){
            	//cout<<jk<<" ";
            //}
            //cout<<endl;
	}
	
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
	cout<<"**************Optimal***************"<<endl;
	cout<<"\033[0m";
	 ifstream inputFile("input.txt");
	 ofstream fout("optimaloutput.txt",ios_base::app);
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
	 pair<int,int> datacaught=optimal_implementation(no_frame,frames_nos);
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
