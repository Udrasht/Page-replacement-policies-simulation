#include <bits/stdc++.h>
using namespace std;
class Node{
	   	public:
	   	Node* left;
	   	
	   	int frq;
	   	Node* right;
	   	int key;
	   	int value;
	   	Node(int k,int v){
	   	
	   	   this->key = k;
	   	
            this->value = v;  
			frq=1; 
		   }
	   };
class my_lfu{
	public:

class List {
	
        Node* head;
        int cur_cap;
        Node* tail;
        
    public:

        List(){
        	cur_cap = 0;
            head = new Node(0, 0);
            
            tail = new Node(0, 0);
            tail->left = head;
            head->right = tail;
            
            
        }
        
        
        
       
         bool empty(){
            return (cur_cap<=0);
        }
        void remove_node(Node* node) {
            
            if(cur_cap!=0){
			
            cur_cap=cur_cap-1;
            Node* temp=node;
            node->left->right = node->right;
            node->right->left = temp->left;
        }
         
        }
        
        void add_front(Node* node) {
            cur_cap=cur_cap+1;
           
          head->right->left=node;
          node->right=head->right;
          head->right=node;
          node->left=head;
        
        }
         Node* remove_start()
		 {

            
            cur_cap=cur_cap-1;
            Node* temp = head->right;
            head->right->right->left=head;
            head->right=head->right->right;
            //cout<<"f";
            return temp;
            
        }
        
        void add_back(Node* node) {
           cur_cap=cur_cap+1;
           //cout<<"him";
           tail->left->right=node;
           node->left=tail->left;
           tail->left=node;
           node->right=tail;
           
        }
    };

    map<int, Node*> map_occ;
    
    int min_freq;
    int max_cap;
    map<int, List> freq;
    int cur_cap;
    
    my_lfu(int cap){
    	cur_cap=0;
    	max_cap=cap;
	}
	 int get(int key)
	 {        
       
        if(max_cap!=0){
		
        if (map_occ.find(key)!= map_occ.end())
		 {
        Node* node;
		node=map_occ[key];
        int v=node->value;
        int f=node->frq;
        List* list1=&freq[f];
        (*list1).remove_node(node);
        if((*list1).empty()){
        	freq.erase(f);
        	if(f==min_freq){
        		min_freq=min_freq+1;
			}
		}
		node->frq=node->frq+1;
		int h=f+1;
		List* list2=&freq[h];
		(*list2).add_back(node);
        return v;
         }
	    else
		{
            return -1;
        }
	}
	else
        {
            return -1;
		}
	}
	bool set(int k,int val){
		if(max_cap==0){
			return false;
		}
		if(map_occ.find(k)!=map_occ.end()){
			//cout<<"b";
			Node * node;
			node=map_occ[k];
			node->value=val;
			 int f=node->frq;
        List* list1=&freq[f];
        (*list1).remove_node(node);
        if((*list1).empty()){
        	freq.erase(f);
        	if(f==min_freq){
        		min_freq=min_freq+1;
			}
		}
		node->frq=node->frq+1;
		int h=f+1;
		List* list2=&freq[h];
		(*list2).add_back(node);
			return true;
		}
		
		if(max_cap<=cur_cap){
		
			
			int f=min_freq;
			cur_cap=cur_cap-1;
			List *list1=&freq[f];	
			//cout<<"c";
			Node* node=(*list1).remove_start();
		
			int temp=node->key;
				
			map_occ.erase(temp);
		
			if((*list1).empty()){
					
				freq.erase(f);
				
			}
			
		}
		Node* demo=new Node(k,val);
		map_occ[k]=demo;
		freq[1].add_back(demo);
		min_freq=1;
		cur_cap=cur_cap+1;
		return false;
	}

};
pair<int,int> nfu_implementation(int no_frame,vector<int> &frames_nos){
	int page_hit=0;
	int page_fault=0;
	//vector<int> frames;
	my_lfu* lfu=new my_lfu(no_frame);
	int lln=frames_nos.size();
	for(int i=0;i<lln;i++){
		if(lfu->set(frames_nos[i],frames_nos[i])){
              page_hit=page_hit+1;
              //cout<<"HIT   "<<"-->"<<frames_nos[i]<<endl;
		}
		else{
			page_fault++;
			//cout<<"FAULT "<<"-->"<<frames_nos[i]<<endl;;
		}
		// for( auto jk : frames){
  //           	cout<<jk<<" ";
  //           }
  //           cout<<endl;
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
	cout<<"**************NFU***************"<<endl;
	cout<<"\033[0m";
	 ifstream inputFile("input.txt");
	 ofstream fout("nfuoutput.txt",ios_base::app);
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
	 pair<int,int> datacaught=nfu_implementation(no_frame,frames_nos);
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
