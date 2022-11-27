#include<iostream>
#include<bits/stdc++.h>

using namespace std;

pair<int,int> clocks(int frame_size, vector<int> frame_nos)
{
    int global_time = 0;
    int thresh = 3;
    int len = frame_nos.size();
    unordered_map<int,int> dicti;
    if(len==0){
        return make_pair(0,0);
    }
    int frame_arr[frame_size];
    int arr[frame_size];
    int time_arr[frame_size];
    int fault = 0;
    int hits = 0;

    for(int i=0;i<len;i++)
    {
        arr[i] = 0;
    }
    int index = 0;
    int j = 0;
    int flag = 0;
    while(j<frame_size)
    {
        global_time+=1;
        if(dicti.find(frame_nos[index])==dicti.end()){
            frame_arr[j] = frame_nos[index];
            time_arr[j] = global_time;
            fault += 1;
            dicti[frame_nos[index]] = j;
            j+=1;
            flag = 0;
        }
        else{
            arr[dicti[frame_nos[index]]] = 1;
            time_arr[dicti[frame_nos[index]]] = global_time;
            hits+=1;
            flag = 1;
        }
        index += 1;
        if(index>=len){
            return make_pair(hits,fault);
        }
    }
    j = index;
    if(flag == 0){
        index = 0;
    }
    int i=j;
    while(i<len)
    {
        if(index == frame_size){
            index = 0;
        }
        if(dicti.find(frame_nos[i])==dicti.end())
        {
            while(arr[index]!=0 && global_time - time_arr[index]<=thresh )
           {
            global_time += 1;
            if(arr[index] == 1)
            {
                arr[index] = 0; 
            }

           // cout<<""
            index += 1;
            //cout<<index<<"\n";
            if(index==frame_size)
            {
                index=0;
            }
           }
           global_time += 1;
           dicti.erase(frame_arr[index]);
           frame_arr[index] = frame_nos[i];
           time_arr[index] = global_time;
           dicti[frame_nos[i]] = index;
           fault+=1;
           index++;
           i++;
        }
        else{
            global_time += 1;
            arr[dicti[frame_nos[i]]] = 1;
            time_arr[dicti[frame_nos[i]]] = global_time;
            hits += 1;
            i++;
        }
    }
    return make_pair(hits,fault);
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
int main()
{
 cout<<"\033[0;31m";
	cout<<"**************Ws Clock***************"<<endl;
	cout<<"\033[0m";
	 ifstream inputFile("input.txt");
	 ofstream fout("wsclockoutput.txt",ios_base::app);
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
	 pair<int,int> datacaught=clocks(no_frame,frames_nos);
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
    //int frame_size = 3;
    //vector<int> arr{2, 5, 10, 1, 2, 2, 6, 9, 1, 2,10,2,6,1,2,1 ,6,9,5,1}; 
    //vector<int> arr2 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0};
    //pair<int,int> datacaught = clocks(frame_size,arr);
    //cout<<"\n";
   // cout<<datacaught.first<<"\n"<<datacaught.second<<"\n";
    return 0;
}
