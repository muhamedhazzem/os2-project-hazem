#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int ql;
int framesize;
const int limit = 100000;

int p[limit];

int m[limit];

void FifoPageReplacement(void)
{
    queue<int> qu;
    int pagefaults = 0;

    for (int i = 0; i < ql; i++)
    {
        
        if (m[p[i]] == true)
        {
            cout << "the page: " << p[i] << " didn't make a page fault\n";
        }
        else
        {
            qu.push(p[i]);
            m[p[i]] = true;
            if (qu.size() > framesize)
            {
                int p = qu.front();
                m[p] = false;
                qu.pop();
            }
            pagefaults++;
            cout << "the page: " << p[i] << " made a page fault\n";
        }

    }
    cout << "\nTotal number of page faults: " << pagefaults;
    return;
}


void OptimalPageReplacement()
{
    vector<int> framev;
    int pagefaults = 0;
    for (int i = 0; i < ql; i++)
    {
        int x;

        for (x = 0; x < framev.size(); x++)
            if (framev[x] == p[i])
                break;

        if (x == framev.size())
        {

            if (framev.size() < framesize)
                framev.push_back(p[i]);

            else
            {

                int indx = i + 1;
                int r = -1, far = indx;
                for (int x = 0; x < framev.size(); x++)
                {
                    int j;
                    for (j = indx; j < ql; j++)
                    {
                        if (framev[x] == p[j])
                        {
                            if (j > far)
                            {
                                far = j;
                                r = x;
                            }
                            break;
                        }
                    }
                    if (j == ql)
                    {
                        r = x;
                        break;
                    }
                }
                framev[r] = p[i];
            }
            pagefaults++;
            cout << "the page: " << p[i] << " made a page fault\n";
        }
        else
        {
            cout << "the page: " << p[i] << " didn't make a page fault\n";
        }
    }
    cout << "\nTotal number of Page Faults: " << pagefaults;
}

int main()

{
    char x;
    cout << "enter your choice: ";
    cin >> x;
    if (x == 'l') {
       

        int framesize = 0;
        
        cout << " Enter the Number of frames: ";
        cin >> framesize;
        int ql, i, count = 0;
        cout << " Enter the queue length: ";
        cin >> ql;
        int* page = new int(ql);
        cout << " Enter the queue: " << "\n";
        for (i = 0; i < ql; i++)
        {
            cout << "\t";
            cin >> page[i];
        }


        int* fr = new int[framesize];
        
        int* fc = new int[framesize];
        
        for (i = 0; i < framesize; i++)
        {
            fr[i] = -1;
            fc[i] = 0; 
        }
        i = 0;
        while (i < ql)
        {
           
            int j = 0, fg = 0;
            while (j < framesize)
            {
                if (page[i] == fr[j]) {  
                    fg = 1;
                    fc[j] = i + 1;
                }

                j++;

            }
            j = 0;
            cout << "\n";
            cout << "the page: " << page[i];
            if (fg == 0)
            {
               

                int min = 0, k = 0;
                while (k < framesize - 1)
                {

                    if (fc[min] > fc[k + 1]) 
                        min = k + 1;

                    k++;



                }
                fr[min] = page[i];
                fc[min] = i + 1;  
                count++;

                
                while (j < framesize)
                {
                    cout << " | " << fr[j] << " | ";
                    j++;
                }

            }
            else
                cout << " didn't make a page fault";

            i++;
        }
        cout << "\n";
        cout << "\nTotal number of Page Faults: " << count;
        return 0;
    }
    else if (x == 'f') {

        cout << "Number of Frames: ";
        cin >> framesize;

        cout << "Enter the queue length: ";
        cin >> ql;

        cout << "Enter the queue: ";
        cout << "\n";
        for (int i = 0; i < ql; i++) {
            cout << "\t";

            cin >> p[i];
        }

        FifoPageReplacement();

        return 0;
    }
    else if (x == 'o')
    {
        cout << "Number of Frames: ";
        cin >> framesize;

        cout << "The queue length: ";
        cin >> ql;

        cout << "the queue:\n";

        for (int i = 0; i < ql; i++) {
            cout << "\t";
            cin >> p[i];
        }
        OptimalPageReplacement();
        return 0;
    }
}