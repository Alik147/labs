#include "Btree.hpp"
#include "AVLtree.hpp"
#include "BtreeDictionary.hpp"
#include "AVLtreeDictionary.hpp"
#include "tests.h"
#include "TicTacToe.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
    startTests();
    string answer = "";
    myvector::SparseVector<int> vec("BTreeDictionary", "ArraySequence", 0);
    dictionary::BTreeDictionary<int, int> tree(2, "ArraySequence", -1, -1);
    dictionary::AVLTreeDictionary<int, int> avl_tree("ArraySequence", -1, -1);
    while(answer != "end"){
        cin>>answer;
        if (answer == "vector"){
            while (answer != "end")
            {
                cout<<"vector>";
                cin>>answer;
                int* mas;
                if (answer == "create")
                {
                    size_t size;
                    cout<<"size:";
                    cin>>size;
                    mas = new int[size];
                    for (size_t i = 0; i < size ; i++)
                    {
                        cin>>mas[i];
                    }
                    for (unsigned int i = 0; i < size; ++i) {
                        vec.append(mas[i]);
                    }
                }
                if (answer == "print")
                {
                    cout<<vec.representation()<<'\n';
                }
                if (answer == "append")
                {
                    int n;
                    cin>>n;
                    vec.append(n);
                }
                if (answer == "prepend")
                {
                    int n;
                    cin>>n;
                    vec.prepend(n);
                }
                if (answer == "swap")
                {
                    int n,m;
                    cin>>n>>m;
                    vec.swap(n,m);
                }
                if (answer == "size")
                {
                    cout<<vec.length()<<'\n';
                }
                if (answer == "remove")
                {
                    int n;
                    cin>>n;
                    vec.pop(n);
                }
                if (answer == "help")
                {
                    cout<<"create"<<'\t'<<"append"<<'\t'<<"print"<<'\t'<<"preprnd"<<'\t'<<"swap"<<'\t'<<"size"<<'\t'<<"pop"<<'\n';
                }
            }
        }
        if (answer == "dict")
        {
           while (answer!="end")
           {
               cout<<"dict>";
               cin>>answer;
               if (answer == "print")
                {
                    cout<<tree<<'\n';
                }
                if (answer == "insert")
                {
                    int n;
                    int v;
                    cin>>n>>v;
                    tree.insert(n, v);
                }
                if (answer == "contains")
                {
                    int n;
                    cin>>n;
                    if (tree.contains(n))
                    {
                        cout<<"TRUE\n";
                    }else{
                        cout<<"FALSE\n";
                    }
                    
                }
                if (answer == "remove")
                {
                    int n;
                    cin>>n;
                    tree.remove(n);
                }
                
           }
           
        }
        if (answer == "TTT"){
            Board brd(3);
            cout<<"Multiplayer? (y/n):";
            cin>>answer;
            bool multi = false;
            if (answer == "y") multi = true;
            int turnPlayer = -1;
            char playerIs = 'X';
            if (!multi)
            {
                    cout<<"U play X or O?:";
                    cin>>answer;
                    if (answer == "O")
                    {
                        playerIs = 'O';
                        brd.Set(1,1,-1);
                        turnPlayer = -turnPlayer;
                    }
            }
            
            while (brd.CheckVictory() == 0)
            {
                brd.PrintBoard();
                if (multi)
                {
                    if (turnPlayer == -1)
                    {
                        cout<<"X TURN!"<<std::endl;
                        int x,y;
                        cin>>x>>y;
                        brd.Set(x,y,-1);
                        turnPlayer = -turnPlayer;
                    }
                    else
                    {
                        cout<<"O TURN!"<<std::endl;
                        int x,y;
                        cin>>x>>y;
                        brd.Set(x,y,1);
                        turnPlayer = -turnPlayer;
                    }  
                } else
                {
                    if ((turnPlayer == -1 && playerIs == 'O') || (turnPlayer == 1 && playerIs == 'X'))
                    {
                        mymove best = brd.GetBestMove(turnPlayer, true);
                        brd.Set(best.x, best.y, turnPlayer);
                        turnPlayer = -turnPlayer;
                    }else
                    {
                        cout<<"UR TURN!"<<std::endl;
                        int x,y;
                        cin>>x>>y;
                        brd.Set(x,y,turnPlayer);
                        turnPlayer = -turnPlayer;
                    }
                }
            }
            brd.PrintBoard();
            int res = brd.CheckVictory();
            if (res == 1)
            {
                cout<< "O WINS !!!"<<'\n'<<endl;
            }
            if (res == -1)
            {
                cout<< "X WINS !!!"<<'\n'<<endl;
            }
            if (res == 2)
            {
                cout<< "TIE"<<'\n'<<endl;
            }
            // cout<<brd.GetBestMove(-1, true).x<<"-"<<brd.GetBestMove(-1, true).y<<std::endl;
            // std::cout<<brd.CheckVictory();
        }
        
    }
    return 0;
}
