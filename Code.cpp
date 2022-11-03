#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
map<string,vector<string>> tag_by_name;
map<string,vector<string>> tag_by_color;
set<string> tag_name;
set<string> tag_clr;
class Input
{
  public:
  bool check(string s)
  {
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            cout<<"No spaces allowed"<<endl;
            return false;
        }
    }
    return true;
   }
    void tag_color(string loc)
    {
       cout<<"Enter 1 to also tag by color or any other key to exit this option"<<endl;
       string k;
       cin>>k;
       if(k!="1") return;
       cout<<"Enter the color"<<endl;
       string color;
       cin>>color;
       if(tag_by_color.find(color)==tag_by_color.end())
        tag_by_color[color].push_back(loc);
        else
        {
           vector<string> present=tag_by_color[color];
           for(string x:present)
           {
            if(x==loc)
            {
               cout<<"Already present"<<endl;
               return;
            }
           }
           tag_by_color[color].push_back(loc);
        }
    }
    void database_by_color()
    {
        ofstream out;
        out.open("database_color.txt",ofstream::out | ofstream::app);
        for(auto it:tag_by_color)
        {
            string tag_1=it.first;
            vector<string> texts_tag_1=it.second;
            for(int i=0;i<texts_tag_1.size();i++)
            {
               string ch=tag_1+"--"+texts_tag_1[i];
               if(tag_clr.find(ch)==tag_clr.end())
               {
                 out<<tag_1<<"--"<<texts_tag_1[i]<<endl;
                 tag_clr.insert(ch);
               }
            }
        }
        out.close();   
    }
    void tag_color1()
    {
       cout<<"Enter the color"<<endl;
       string color;
       cin>>color;
       cout<<"Enter the file location"<<endl;
       string loc;
       cin>>loc;
       if(tag_by_color.find(color)==tag_by_color.end())
        tag_by_color[color].push_back(loc);
        else
        {
           vector<string> present=tag_by_color[color];
           for(string x:present)
           {
            if(x==loc)
            {
               cout<<"Already present"<<endl;
               return;
            }
           }
           tag_by_color[color].push_back(loc);
        }
        database_by_color();
    }
    void database()
    {
        ofstream out;
        out.open("database.txt",ofstream::out | ofstream::app);
        for(auto it:tag_by_name)
        {
            string tag_1=it.first;
            vector<string> texts_tag_1=it.second;
            for(int i=0;i<texts_tag_1.size();i++)
            {
               string ch=tag_1+"--"+texts_tag_1[i];
               if(tag_name.find(ch)==tag_name.end())
               {
                 out<<tag_1<<"--"<<texts_tag_1[i]<<endl;
                 tag_name.insert(ch);
               }
            }
        }
        out.close();   
    }
    void input1(){
        cout<<"How would you like to enter data?\n";
        cout<<"Press 1 for tag by name \nPress any other key for tag by color\n";
        string choice;
        cin>>choice;
        if(choice=="1")
        input();
        else
        tag_color1();
    }
    void input()
    {
        cout<<"Enter the tag"<<endl;
        string tag;
        cin>>tag;
        bool k=check(tag);
        if(!k) return;
        cout<<"Enter the file location"<<endl;
        string loc;
        cin>>loc;
        if(tag_by_name.find(tag)==tag_by_name.end())
        tag_by_name[tag].push_back(loc);
        else
        {
           vector<string> present=tag_by_name[tag];
           for(string x:present)
           {
            if(x==loc)
            {
               cout<<"Already present"<<endl;
               return;
           }
           }
           tag_by_name[tag].push_back(loc);
        }
        tag_color(loc);
        database();
        database_by_color();
        return;
    }
    void input_par(string loc,string tag)
    {
      bool k=check(tag);
      if(!k) return;
      if(tag_by_name.find(tag)==tag_by_name.end())
      tag_by_name[tag].push_back(loc);
      else
      {
         vector<string> present=tag_by_name[tag];
         for(string x:present)
         {
          if(x==loc)
          {
             cout<<"Already present"<<endl;
             return;
         }
         }
         tag_by_name[tag].push_back(loc);
      }
      database();
    }
    void input_par_color(string loc,string color)
    {
        if(tag_by_color.find(color)==tag_by_color.end())
        tag_by_color[color].push_back(loc);
        else
        {
           vector<string> present=tag_by_color[color];
           for(string x:present)
           {
            if(x==loc)
            {
               cout<<"Already present"<<endl;
               return;
            }
           }
           tag_by_color[color].push_back(loc);
         }
         database_by_color();
    }
};
class Preprocessing
{
    public:
    void preprocess_tag_by_name()
    {
       ifstream in("database.txt");
       string st;
       getline(in,st);
       while (st!="")
       {
          string key="",value="";
          int i=0;
          for(i=0;i<st.length();i++)
          {
             if(st[i]=='-' && st[i+1]=='-')
             break;
             else
             key+=st[i];
          }
          i+=2;
          for(;i<st.length();i++)
          {
             if(st[i] != ' ')
             value+=st[i];
             else
             break;
          }
          tag_by_name[key].push_back(value);
          string k=key+"--"+value;
          tag_name.insert(k);
          getline(in,st);
       }
    }
    void preprocess_tag_by_color()
    {
       ifstream in("database_color.txt");
       string st;
       getline(in,st);
       while (st!="")
       {
          string key="",value="";
          int i=0;
          for(i=0;i<st.length();i++)
          {
             if(st[i]=='-' && st[i+1]=='-')
             break;
             else
             key+=st[i];
          }
          i+=2;
          for(;i<st.length();i++)
          {
             if(st[i] != ' ')
             value+=st[i];
             else
             break;
          }
          tag_by_color[key].push_back(value);
           string k=key+"--"+value;
          tag_clr.insert(k);
          getline(in,st);
       }
    }
    bool is_file_exist(const char *fileName)
    {
    std::ifstream infile(fileName);
    return infile.good();
    }
    void process()
    {
       bool check1=is_file_exist("database.txt");
       bool check2=is_file_exist("database_color.txt");
       if(check1)
       preprocess_tag_by_name();
       if(check2)
       preprocess_tag_by_color();
       return;
    }
};
class Search
{
   public:
   // lcs function is to find tags with longest common character subsequence when tag entered is not correct
   string lcs(string s, string t)
   {
    int n=s.length();
    int m=t.length();
	 vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++)
    dp[0][j]=0;
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n,j=m;
    string ans;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(),ans.end()); return ans;  
   }
   vector<string> longestCommonSubsequence(vector<string> &tag, string text2)
   {
        vector<string> v;
        int maxi=0;
        for(int i=0;i<tag.size();i++)
        {
           string str=lcs(tag[i],text2);
           if(str.length()>maxi)
           {
             while(v.size()>0)
             v.pop_back();
             v.push_back(tag[i]);
             maxi=str.length();
           }
           else if(str.length()==maxi && maxi!=0)
           v.push_back(tag[i]); 
         }
          return v;
   }
   void related_search_by_name(string s)
   {
      vector<string> potential_search;
      for(auto it:tag_by_name)
      potential_search.push_back(it.first);
      vector<string> ans=longestCommonSubsequence(potential_search,s);
      if(ans.size()==0)
      cout<<"No related searches"<<endl;
      else 
      {
         cout<<"Do you mean to search:"<<endl;
         for(string x:ans)
         cout<<x<<endl;
      }
   }
   void related_search_by_color(string s)
   {
      vector<string> potential_search;
      for(auto it:tag_by_color)
      potential_search.push_back(it.first);
      vector<string> ans=longestCommonSubsequence(potential_search,s);
      if(ans.size()==0)
      cout<<"No related searches"<<endl;
      else 
      {
         cout<<"Do you mean to search:"<<endl;
         for(string x:ans)
         cout<<x<<endl;
      }
   }
   void check_by_name(string s)
   {
      vector<string> ans;
      if(tag_by_name.find(s)!=tag_by_name.end())
      ans=tag_by_name[s];
      else
      {
         related_search_by_name(s);
         return;
      }
      cout<<"Required locations are :"<<endl;
      for(string x:ans)
      cout<<x<<endl;
   }
   void check_by_color(string s)
   {
      vector<string> ans;
      if(tag_by_color.find(s)!=tag_by_color.end())
      ans=tag_by_color[s];
      else
      {
         related_search_by_color(s);
         return;
      }
      cout<<"Required locations are :"<<endl;
      for(string x:ans)
      cout<<x<<endl;
   }
};
class Display
{
   public:
   void disp_by_name()
   {
      cout<<"Tags by name are:"<<endl;
      for(auto it:tag_by_name)
      cout<<it.first<<endl;
   }
   void disp_by_color()
   {
      cout<<"Tags by color are:"<<endl;
      for(auto it:tag_by_color)
      cout<<it.first<<endl;
   }
   void visual(string s)
   {
      if(s=="1")
      disp_by_name();
      else if(s=="2")
      disp_by_color();
      else
      {
         disp_by_name();     
         disp_by_color();
      }
   }
};
class Delete
{
   public:
   void delete_from_name_file(string s)
   {
      string inp;
      ifstream fin;
      fin.open("database.txt");
      ofstream dup;
      dup.open("dup.txt");
      while (getline(fin,inp))
      {
          if (inp != s)
          dup<<inp<<endl;
      }
      dup.close();
      fin.close();
      remove("database.txt");
      rename("dup.txt","database.txt");
   }
   void delete_from_color_file(string s)
   {
      string inp;
      ifstream fin;
      fin.open("database_color.txt");
      ofstream dup;
      dup.open("dup.txt");
      while (getline(fin,inp))
      {
          if (inp != s)
          dup<<inp<<endl;
      }
      dup.close();
      fin.close();
      remove("database_color.txt");
      rename("dup.txt","database_color.txt");
   }
   void delete_from_name(string tag,string fl)
   {
      if(tag_by_name.find(tag)==tag_by_name.end())
      {
         cout<<"No such tag found"<<endl;
         return;
      }
      vector<string> present=tag_by_name[tag];
      for(string x:present)
      {
         if(x==fl)
         {
            string s=tag+"--"+fl;
            cout<<s<<endl;
            delete_from_name_file(s);
            if(tag_name.find(s)!=tag_name.end()) tag_name.erase(s);
            tag_by_name.erase(tag);
            for(string y:present)
            {
                if(y!=x)
                tag_by_name[tag].push_back(y);
            }
            return;
         }
      }
      cout<<"No such file found in that tag name"<<endl;
      return;
   }
   void delete_from_color(string tag,string fl)
   {
      if(tag_by_color.find(tag)==tag_by_color.end())
      {
         cout<<"No such tag found"<<endl;
         return;
      }
      vector<string> present=tag_by_color[tag];
      for(string x:present)
      {
         if(x==fl)
         {
            string s=tag+"--"+fl;
            cout<<s<<endl;
            if(tag_clr.find(s)!=tag_clr.end()) tag_clr.erase(s);
            delete_from_color_file(s);
            tag_by_color.erase(tag);
            for(string y:present)
            {
                if(y!=x)
                tag_by_color[tag].push_back(y);
            }
            return;
         }
      }
      cout<<"No such file found in that tag color"<<endl;
      return;
   }
};
class Rename
{
   public:
   Delete del;
   Input ip;
   void rename_name_file(string old_file,string new_file)
   {
      vector<string> present_tag;
      for(auto it:tag_by_name)
      {
         vector<string> tags=it.second;
         for(string x:tags)
         {
            if(x==old_file)
            present_tag.push_back(it.first);
         }
      }
      if(present_tag.size()==0)
      {
         cout<<"No such file found in name tag"<<endl;
         return;
      }
      for(string x:present_tag)
      {
         del.delete_from_name(x,old_file);
         ip.input_par(new_file,x);
      }
   }
   void rename_color_file(string old_file,string new_file)
   {
      vector<string> present_tag;
      for(auto it:tag_by_color)
      {
         vector<string> tags=it.second;
         for(string x:tags)
         {
            if(x==old_file)
            present_tag.push_back(it.first);
         }
      }
      if(present_tag.size()==0)
      {
         cout<<"No such file found in color tag"<<endl;
         return;
      }
      for(string x:present_tag)
      {
         del.delete_from_color(x,old_file);
         ip.input_par_color(new_file,x);
      }
   }
   void rename_the_file(string old_file,string new_file)
   {
       rename_name_file(old_file,new_file);
       rename_color_file(old_file,new_file);
   }
};
int main()
{
    string n="1";
    Preprocessing prx;
    Input ip;
    Display dsp;
    Search src;
    Delete del;
    Rename ren;
    // First doing the preprocessing of the stored data
    prx.process();
    while(1>0)
    {
       cout<<"Enter 1 to create tag \nEnter 2 to search tag \nEnter 3 to view all the tags \nEnter 4 to delete file from the taging \nEnter 5 to update the tag \nEnter 6 to rename the file location \n Press any other key to exit"<<endl;
       cin>>n;
       if(n=="1")
       ip.input1();
       else if(n=="2")
       {
         cout<<"Enter 1 to search by name \nPress any other key to search by color"<<endl;
         string na;
         cin>>na;
         if(na=="1")
         {
         cout<<"Enter the name"<<endl;
         string s;
         cin>>s;
         src.check_by_name(s);
         }
         else
         {
         cout<<"Enter the color"<<endl;
         string s;
         cin>>s;
         src.check_by_color(s);
         }
       }
       else if(n=="3")
       {
         cout<<"Enter 1 to view all name tags \nEnter 2 to view all color tags \nEnter 3 to view all tags"<<endl;
         string s;
         cin>>s;
         dsp.visual(s);
       }
       else if(n=="4")
       {
         cout<<"Enter 1 to delete the file from name tag \nElse to delete from color tag"<<endl;
         string s;
         cin>>s;
         if(s=="1")
         {
            
             string tg,fl; 
             cout<<"Enter the tag name from where you want to delete : "<<endl;
             cin>>tg;
             cout<<"Enter the file to be deleted"<<endl;
             cin>>fl;
             del.delete_from_name(tg,fl);
         }
         else
         {
             string tg,fl;
             cout<<"Enter the tag color from where you want to delete "<<endl;
             cin>>tg;
             cout<<"Enter the file to be delete"<<endl;
             cin>>fl;
             del.delete_from_color(tg,fl);
         }
       }
       else if(n=="5")
       {
          cout<<"How would you like to update tag?\n1.Update by tag name\n2.Update by tag colour"<<endl;
          string choice;
          cin>>choice;
          if(choice=="1"){
          string prev,fl,nw;
          cout<<"Enter the tag where the file was stored earlier"<<endl;
          cin>>prev;
          cout<<"Enter the file to be updated"<<endl;
          cin>>fl;
          cout<<"Enter the tag where you want to update it"<<endl;
          cin>>nw;
          ip.input_par(fl,nw);
          del.delete_from_name(prev,fl);
          }
          else{
             string prev,fl,nw;
             cout<<"Enter the tag where the file was stored earlier"<<endl;
             cin>>prev;
             cout<<"Enter the file to be updated"<<endl;
             cin>>fl;
             cout<<"Enter the tag where you want to update it"<<endl;
             cin>>nw;
             ip.input_par_color(fl,nw);
             del.delete_from_color(prev,fl);
          }
       }
       else if(n=="6")
        {
          cout<<"Enter the old file location"<<endl;
          string old_file;
          cin>>old_file;
          cout<<"Enter the new file location you want to replace with"<<endl;
          string new_file;
          cin>>new_file;
          ren.rename_the_file(old_file,new_file);
        }
       else
       break; 
    }
    return 0;
}
