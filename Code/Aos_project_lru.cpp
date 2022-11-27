#include<bits/stdc++.h>
#include <ctime>
using namespace std;

class LNode{

   
    
    public:

    int key;
    int value;
    LNode* left;
    LNode* right;

    
    LNode(int i,int j){
        key=i;
        value=j;
        left=NULL;
        right=NULL;
    }
    
    
};



class LRUCache {
public:
    int csize;
    LNode* head=new LNode(-1,-1);
LNode* tail=new LNode(-1,-1);
unordered_map<int,LNode*> mp;

LNode * addNode(int k, int v){
    LNode* newNode=new LNode(k,v);
    newNode->left=head;
    newNode->right=head->right;
    head->right=newNode;
    newNode->right->left=newNode;
    return newNode;

   

}

void deleteNode(LNode* nodeAddress){
    
        LNode * temp=nodeAddress;
        nodeAddress->left->right=temp->right;
        
        nodeAddress->right->left=temp->left;
        
        
    
        
    
    
    


}
LNode * switchmru(LNode* nodeAddress,int ke,int val){
     LNode * res;
    
    deleteNode(nodeAddress);
   
     res=addNode(ke,val);
   
        
    
     return res;
}
    
    LRUCache(int capacity) {
         
        head->right=tail;
        
        tail->left=head;
         csize=capacity;
        
        
        
    }
    
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }else{
            
            LNode* res;
            res=switchmru(mp[key],key,mp[key]->value);
            
           // mp.erase(key);
            mp[key]=res;

            return res->value;
        }
        
        
    }
    
    bool set(int key, int value) {
        
         LNode * returnadd;

       if(mp.find(key)==mp.end()){ 
           
          if(mp.size()==csize){
           // cout<<"tan tan";
              
            int kci=tail->left->key;

            
            deleteNode(tail->left);
              mp.erase(kci);

            returnadd=addNode(key, value);
            mp[key]=returnadd;
              
            
            

            }else{
              
               if(mp.size()<csize){
                    //cout<<"tin tin";
                 returnadd=addNode(key, value);
                    mp[key]=returnadd;
                }
              
             }
        return false;
             
       }
        else{
             
            returnadd=switchmru(mp[key],key,value);
            //mp.erase(key);
            mp[key]=returnadd;
            
            
            
         return true;   
        }
    }
};


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
pair<int,int> lru_implementation(int no_frame,vector<int>& frames_nos){

    // srand(time(0));
    int size_of_requests=frames_nos.size();
    int capacity=no_frame;
    int page_hit=0;
    int page_fault=0;
    // map<int ,int> mp;
    // vector<int> window;
    LRUCache cache(capacity);
    for(int i=0;i<size_of_requests;i++){

         if(cache.set(frames_nos[i],frames_nos[i])){
           page_hit++;
         }else{
            page_fault++;
         }

        // if(mp.find(frames_nos[i])==mp.end()){
        //     if(window.size()<capacity){
        //         // mp[frames_nos[i]]=new page(frames_nos[i],i);
        //          for(auto it:mp){
        //             it.second++;

        //         }

        //          window.push_back(frames_nos[i]);
        //          mp[frames_nos[i]]=0;



        //     }else{
        //          int ind=(rand() % capacity);
        //         for(auto it:mp){
        //             if(it.second==ind){
        //                 mp.erase(it.first);
        //                 mp[frames_nos[i]]=ind;
        //                 window[ind]=frames_nos[i];
        //                 break;
        //                 // window.
        //             }

        //         }
        //         // mp[frames_nos[i]]=new page(frames_nos[i],i);

        //     }
        //     page_fault++;
        // }else{
        //     //  mp[frames_nos[i]]->latest_ind_no=i;
        //      page_hit++;
        //     //  for(auto it:mp){
        //     //         if(it.second->latest_ind_no<i-capacity+1){
        //     //             mp.erase(it.first);
        //     //             break;
        //     //             // window.
        //     //         }

        //     //     }



        // }
    }
    return {page_hit,page_fault};

    
}
int main(){
	  cout<<"\033[0;31m";
	cout<<"*****LRU Replacement Policy******"<<endl;
	cout<<"\033[0m";
	 ifstream inputFile("input.txt");
	 ofstream fout("lruoutput.txt",ios_base::app);
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
	 pair<int,int> datacaught=lru_implementation(no_frame,frames_nos);
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
