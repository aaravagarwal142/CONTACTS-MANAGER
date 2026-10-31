#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include<unordered_map>

void addcontact(std::vector<std::pair<std::string,long>> &contacts);
void search(std::vector<std::pair<std::string,long>> &contacts);
void deletecontact(std::vector<std::pair<std::string,long>> &contacts);
void listall(std::vector<std::pair<std::string,long>> &contacts);
void generate(std::vector<std::pair<std::string,long>> &contacts);
bool findcontact(std::vector<std::pair<std::string,long>> &contacts,std::string name);
void clear(std::vector<std::pair<std::string,long>> &conatacts);
void benchmark(std::vector<std::pair<std::string,long>> &contacts);
void hashing(std::unordered_map<std::string,long> &hash1);
void clearhash(std::unordered_map<std::string,long> &hash1);
void searchhash(std::unordered_map<std::string,long> &hash1);
void hashing2(std::unordered_map<long , std::string> &hash2);
void clearhash2(std::unordered_map<long , std::string> &hash2);
void searchhash2(std::unordered_map<long , std::string> &hash2);

int main()
{std::unordered_map<std::string,long> hash1;
   hash1.reserve(100000);
std::unordered_map<long,std::string> hash2;
hash2.reserve(100000);

std::vector<std::pair<std::string,long>> contacts;
int n=0;
 int c=0;
std::cout<<"Enter 1 to start"<<"\n";
std::cin>>n;
while(n==1)
{
    
   
    std::cout<<"Enter your choice of operation"<<"\n"<<"1 for adding contact"<<"\n"<<"2 for searching"<<"\n"<<"3 for deleting a contact"<<"\n"<<"4 for listing all contacts"<<"\n";
    std::cout<<"5 for generating random contacts"<<"\n";
    std::cout<<"6 for clearing everything "<<"\n";
    std::cout<<"7 for benchmark "<<"\n";
    std::cout<<"8 for hashing"<<"\n";
    std::cout<<"9 for clearing hash"<<"\n";
    std::cout<<"10 for searching in hash benchmarks"<<"\n";
    std::cout<<"11 for hashing 2"<<"\n";
    std::cout<<"12 for clearing hash 2"<<"\n";
    std::cout<<"13 for searching hash 2 benchmark "<<"\n";
    std::cin>>c;           
    switch(c)
    {
        case 1: addcontact(contacts);
        break;
        case 2: search(contacts);
        break;
        case 3: deletecontact(contacts);
        break;
        case 4: listall(contacts);
        break;
        case 5: generate(contacts);
        break;
        case 6:clear(contacts);
        break;
        case 7:benchmark(contacts);
        break;
        case 8:hashing(hash1);
        break;
        case 9:clearhash(hash1);
        break;
        case 10:searchhash(hash1);
        break;
        case 11:hashing2(hash2);
        break;
        case 12:clearhash2(hash2);
        break;
        case 13:searchhash2(hash2);
        break;

        default: std::cout<<"Enter valid choice"<<"\n";
                  break;    
        
    }
    
    std::cout<<"Enter 1 if you wish to continue,0 is you want to stop "<<"\n";
std::cin>>n;
}

}

void addcontact(std::vector<std::pair<std::string,long>> &contacts)
{std::string name;
     long number;
     
     std::cout<<"Enter the name and number of person- "<<"\n";
     std::cin>>name;
     std::cin>>number;
     std::pair<std::string,long> p;
     p={name,number};
     contacts.push_back(p);
    
}

void search(std::vector<std::pair<std::string,long>> &contacts)
{
    std::cout<<"Enter the name you want to search- "<<"\n";
    std::string name;
    std::cin>>name;
    bool a=true;
    for(int i=0;i<contacts.size();i++)
    {
        if(contacts[i].first==name)
        {
            std::cout<<"Contact No. Found- ";
            std::cout<<contacts[i].second<<"\n";
            a=false;
            break;

        }
        
    }
    if(a==true)
    {
        std::cout<<"Contact not found"<<"\n";
    }

}

void deletecontact(std::vector<std::pair<std::string,long>>&contacts)
{
    std::cout<<"Enter the name you want to delete- "<<"\n";
    std::string name;
    std::cin>>name;
    bool a=true;
    for(int i=0;i<contacts.size();i++)
    {
        if(contacts[i].first==name)
        {
            contacts.erase(contacts.begin()+i,contacts.begin()+i+1);
            a=false;
            break;
        }
       
    }
    if(a==true)
    {
        std::cout<<"Contact not found"<<"\n";
    }
}

void listall(std::vector<std::pair<std::string,long>>&contacts)
{
    std::cout<<"Stored Contacts Are- "<<"\n";
    for (int i=0;i<contacts.size();i++)
    {
        std::cout<<i+1<<"."<<" "<<contacts[i].first<<"-"<<contacts[i].second<<"\n";
    }
}

void generate(std::vector<std::pair<std::string,long>> &contacts)
{int n=0;
    std::cout<<"Enter the number of contacts you want to generate- "<<"\n";
    std::cin>>n;
    contacts.reserve(n);
    for(int i=0;i<n;i++)
    {
        std::string name="name"+std::to_string(i);
        long number=i;
        std::pair<std::string,long> p;
        p={name,number};
        contacts.push_back(p);
        
    }
}

bool findcontact(std::vector<std::pair<std::string,long>> &contacts,std::string name)
{
    
    
    bool a=false;
    for(int i=0;i<contacts.size();i++)
    {
        if(contacts[i].first==name)
        {
            
            a=true;
            break;

        }
        
    }
    return a;

}

void clear(std::vector<std::pair<std::string,long>> &contacts)
{
    contacts.clear();
}

void benchmark(std::vector<std::pair<std::string,long>> &contacts)
{  std::vector<std::string> batch1;
    batch1.reserve(contacts.size());
    for(int i=0;i<contacts.size();i++)
    {std::string name="name"+std::to_string(i);
        batch1.push_back(name);
    }

    std::vector<std::string> batch2;
    batch2.reserve(50000);
    for(int i=0;i<50000;i++)
    {std::string name="nobody"+std::to_string(i);
        batch2.push_back(name);
    }
    
    
    auto start=std::chrono::steady_clock::now();
     int found =0;
    for (int i=0;i<contacts.size();i++)
    {
        
        if(findcontact(contacts,batch1[i])==true)
        {
            found++;
        }
    }
    for(int j=0;j<50000;j++)
    {
       
        if(findcontact(contacts,batch2[j])==true)
        {
            found++;
        }
    }
auto end=std::chrono::steady_clock::now();
auto elapsed=std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
std::cout<<"Vector time is "<<elapsed.count()<<" milliseconds"<<"\n";
std::cout<<found<<" contacts found"<<"\n";
}

void hashing(std::unordered_map<std::string,long> &hash1)
{
   
   for(int i=0;i<100000;i++)
   {
    std::string name="name"+std::to_string(i);
    hash1.insert({name,i});
   } 
   
}

void clearhash(std::unordered_map<std::string,long> &hash1)
{
  hash1.clear();
}

void searchhash(std::unordered_map<std::string,long> &hash1)
{int found=0;
    std::vector<std::string> batch1;
    batch1.reserve(100000);
    for(int i=0;i<100000;i++)
    {std::string name="name"+std::to_string(i);
        batch1.push_back(name);
    }
    std::vector<std::string> batch2;
    batch2.reserve(50000);
    for(int i=0;i<50000;i++)
    {std::string name="nobody"+std::to_string(i);
        batch2.push_back(name);
    }

    auto start1=std::chrono::steady_clock::now();

    for(int i=0;i<100000;i++)
    {
        auto it=hash1.find(batch1[i]);
        if(it!=hash1.end())
        {
            found++;
        }
    }
    for(int i=0;i<50000;i++)
    {
        auto it=hash1.find(batch2[i]);
        if(it!=hash1.end())
        {
            found++;
        }
    }

    auto end1=std::chrono::steady_clock::now();
    auto elapsed1=std::chrono::duration_cast<std::chrono::milliseconds>(end1-start1);
    std::cout<<"Hashing time is "<<elapsed1.count()<<" milliseconds"<<"\n";
    std::cout<<found<<" -no of contacts found"<<"\n";
}

void hashing2(std::unordered_map<long , std::string> &hash2)
{hash2.reserve(100000);
    for(int i=0;i<100000;i++)
    {std::string name="name"+std::to_string(i);
        hash2.insert({i,name});

    }
}

void clearhash2(std::unordered_map<long , std::string> &hash2)
{
    hash2.clear();
}

void searchhash2(std::unordered_map<long , std::string> &hash2)
{int found =0;
    auto start2=std::chrono::steady_clock::now();
  for(int i=0;i<100000;i++)
  {
    auto it=hash2.find(i);
    if(it!=hash2.end())
    {
        found++;
    }
  }
  for(int i=0;i<50000;i++)
  {
    auto it=hash2.find(i+500000);
    if(it!=hash2.end())
    {
        found++;
    }
  }
  auto end2=std::chrono::steady_clock::now();
  auto elapsed2=std::chrono::duration_cast<std::chrono::milliseconds>(end2-start2);
  std::cout<<"2nd hash map timings are "<<elapsed2.count()<<" milliseconds"<<"\n";
  std::cout<<found<<" -contacts found"<<"\n";
}
