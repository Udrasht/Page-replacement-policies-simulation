#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <fstream>
#include <sstream>
using namespace std;


pair<int, int> fifo(int n, vector<int> pages)
{
    int page_fault = 0, page_hit = 0;
    queue<int> frames_queue;
    unordered_set<int> frames_set;
    for( auto page : pages )
    {
        if( frames_set.find(page) == frames_set.end() )
        {
            if( frames_queue.size() == n )
            {
                frames_set.erase(frames_queue.front());
                frames_queue.pop();
            }
            frames_queue.push(page);
            frames_set.insert(page);
            page_fault++;
        }
        else
            page_hit++;
    }
    return {page_hit, page_fault};
}

void string_to_vector(string str, vector<int>& v)
{
    v.clear();
    string page;
    stringstream ss(str);
    while( ss >> page )
    {
        v.push_back(stoi(page));
        //cout << page << " ";
    }
    //cout << endl << str << endl;
}

int main()
{
    cout<<"\033[0;31m";
    cout<<"**************FIFO***************"<<endl;
    cout<<"\033[0m";
    ifstream inputFile("input.txt");
    ofstream fout("fifo_output.txt", ios_base::app);
    string str;
    int frame_ctr;
    vector<int> pages;
    
    while( getline(inputFile, str) )
    {    int pagehit;
    	 int pagefault;
        frame_ctr = stoi(str);
        getline(inputFile, str);
        string_to_vector(str, pages);
        getline(inputFile, str);
       
        pair<int, int> datacaught = fifo(frame_ctr, pages);
        pagehit=datacaught.first;
	 pagefault=datacaught.second;
	 int flen=pages.size();

	 cout<<"Number of frame in MM: "<<frame_ctr<<endl;
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

        fout << frame_ctr << " " <<pagefault<< " " <<pagehit<< " " <<flen<< endl;
    }
    inputFile.close();
    fout.close();
    return 0;
}
