#include <iostream>
#include <fstream>

using namespace std;

long long intr,ctxt,btime,processes,procs_running,procs_blocked;
void Doit(string str)
{
    if(str[0]=='c')
    {
        if(str[1]!='t')//as cpu0 cpu1 .. :)
        {
            return;
        }
        else
        {
            string tmp_="0";
            for (int i = 5; i < str.length(); i++)
            {

              tmp_+=str[i];

            }
              ctxt=stoi(tmp_);
        }
    }

    else if(str[0]=='i')
    {
        string tmp_="0";
        for (int i = 5; i < str.length(); i++)
        {
            if(str[i]==' ' ||str[i]=='\n')
            {
                break;
            }
            tmp_+=str[i];

        }
         intr=stoi(tmp_);
    }

    else  if(str[0]=='b')
    {
        string tmp_="0";
        for (int i = 6; i < str.length(); i++)
        {
            if(str[i]==' ' ||str[i]=='\n')
            {
                break;
            }
            tmp_+=str[i];

        }
         btime=stoi(tmp_);
    }

    else if(str[0]=='p')
    {

        if(str[6]=='s')
        {
            string tmp_="0";
            for (int i = 10; i < str.length(); i++)
            {
                if(str[i]==' ' ||str[i]=='\n')
                {
                    break;
                }
                tmp_+=str[i];

            }
            processes=stoi(tmp_);
        }
        else if(str[6]=='r')
        {
            string tmp_="0";
            for (int i = 14; i < str.length(); i++)
            {
                if(str[i]==' ' ||str[i]=='\n')
                {
                    break;
                }
                tmp_+=str[i];

            }
            procs_running=stoi(tmp_);

        }
        else
        {
            string tmp_="0";
            for (int i = 14; i < str.length(); i++)
            {
                if(str[i]==' ' ||str[i]=='\n')
                {
                    break;
                }
                tmp_+=str[i];

            }
            procs_blocked=stoi(tmp_);
        }

    }


}

int main()
{

    string line;
    ifstream myfile ("/proc/stat");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            Doit(line);
        }
        myfile.close();
    }

    else
    {
        cout << ":( ";
    }

    cout<<"intr: "<<intr<<"\n";
    cout<<"ctxt: "<<ctxt<<"\n";
    cout<<"btime: "<<btime<<"\n";
    cout<<"processes: "<<processes<<"\n";


    return 0;
}
