#include<bits/stdc++.h>
#include <ctime>
using namespace std;

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
class page{
    public:
    int page_no;
    int latest_ind_no;
    page(int pno,int l_in_n){
        page_no=pno;
        latest_ind_no=l_in_n;
    }
};
pair<int,int> Nru_implementation(int no_frame,vector<int>& frames_nos,vector<int>& modified_bit){

    // srand(time(0));
    int size_of_requests=frames_nos.size();
    int capacity=no_frame;
    int page_hit=0;
    int page_fault=0;
    unordered_map<int ,vector<int>> mp;
    map<int,int> check;
    vector<int> window;
    for(int i=0;i<size_of_requests;i++){
        if(i%10==0){
            for(auto it:mp[2]){
                mp[0].push_back(it);
                check[it]=0;
            }
             for(auto it:mp[3]){
                mp[1].push_back(it);
                check[it]=1;
            }

        }
        if(check.find(frames_nos[i])==check.end()){
            if(window.size()<capacity){
                // mp[frames_nos[i]]=new page(frames_nos[i],i);
                 window.push_back(frames_nos[i]);
                 
                 if(modified_bit[i]){
                     mp[3].push_back(frames_nos[i]);
                     check[frames_nos[i]]=3;
                 }else{
                    mp[2].push_back(frames_nos[i]);
                    check[frames_nos[i]]=2;
                 }
                //  mp[frames_nos[i]][0]=1;
                 
                




            }else{
                //  int ind=(rand() % capacity);
                if(mp[0].size()!=0){
                    check.erase(mp[0][0]);
                    mp[0].erase(mp[0].begin());
                }else if(mp[1].size()!=0){
                    check.erase(mp[1][0]);
                    mp[1].erase(mp[1].begin());
                }else if(mp[2].size()!=0){
                    check.erase(mp[2][0]);
                    mp[2].erase(mp[2].begin());
                }else if(mp[3].size()!=0){
                    check.erase(mp[3][0]);
                    mp[3].erase(mp[3].begin());
                }

                // check[frames_nos[i]]=1;
                 if(modified_bit[i]){
                     mp[3].push_back(frames_nos[i]);
                     check[frames_nos[i]]=3;
                 }else{
                    mp[2].push_back(frames_nos[i]);
                    check[frames_nos[i]]=2;
                 }



                // mp.erase(it.first);
                        // mp[frames_nos[i]]=ind;
                        // window[ind]=frames_nos[i];
                        // break;
                        // window.
                // mp[frames_nos[i]]=new page(frames_nos[i],i);

            }
            page_fault++;
        }else{
            //  mp[frames_nos[i]]->latest_ind_no=i;
             page_hit++;
             if(check[frames_nos[i]]==0){
                auto inditr=find(mp[0].begin(),mp[0].end(),frames_nos[i]);
                int ind=inditr-mp[0].begin();
                mp[0].erase(inditr);
                if(modified_bit[i]){
                    mp[3].push_back(frames_nos[i]);
                     check[frames_nos[i]]=3;

                }else{
                     mp[2].push_back(frames_nos[i]);
                     check[frames_nos[i]]=2;

                }
             }else if(check[frames_nos[i]]==1){
                auto inditr=find(mp[1].begin(),mp[1].end(),frames_nos[i]);
                int ind=inditr-mp[1].begin();
                mp[1].erase(inditr);
                
                    mp[3].push_back(frames_nos[i]);
                     check[frames_nos[i]]=3;

                
             }else if(check[frames_nos[i]]==2){
                auto inditr=find(mp[2].begin(),mp[2].end(),frames_nos[i]);
                int ind=inditr-mp[2].begin();
                mp[2].erase(inditr);
                if(modified_bit[i]){
                    mp[3].push_back(frames_nos[i]);
                     check[frames_nos[i]]=3;

                }else{
                    mp[2].push_back(frames_nos[i]);
                     check[frames_nos[i]]=2;

                }
             }else if(check[frames_nos[i]]==3){
                auto inditr=find(mp[3].begin(),mp[3].end(),frames_nos[i]);
                int ind=inditr-mp[3].begin();
                mp[3].erase(inditr);
                
                    mp[3].push_back(frames_nos[i]);
                     check[frames_nos[i]]=3;

                
             }
            //  mp[check[frames_nos[i]]]


            //  for(auto it:mp){
            //         if(it.second->latest_ind_no<i-capacity+1){
            //             mp.erase(it.first);
            //             break;
            //             // window.
            //         }

            //     }



        }
    }
    return {page_hit,page_fault};

    
}
int main(){
	  cout<<"\033[0;31m";
	cout<<"*****NRU******"<<endl;
	cout<<"\033[0m";
	 ifstream inputFile("input.txt");
	 ofstream fout("nruoutput.txt",ios_base::app);
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
        vector<int> modified_bit;
	 	getline(inputFile,str);
        string_to_frame_vector(str,modified_bit);
	 pair<int,int> datacaught=Nru_implementation(no_frame,frames_nos,modified_bit);
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
