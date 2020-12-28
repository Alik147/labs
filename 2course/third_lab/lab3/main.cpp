#include "Btree.hpp"
#include "AVLtree.hpp"
#include "BtreeDictionary.hpp"
#include "AVLtreeDictionary.hpp"
#include "tests.h"
#include "UndirectedGraph.hpp"

int main(int argc, char const *argv[])
{
    //1 test
    graph::UndirectedGraph<int, std::string> myGraph1("BTreeDictionary", "ArraySequence", 0, "null");
    myGraph1.addNode("1");
    myGraph1.addNode("2");
    myGraph1.addNode("3");
    myGraph1.addNode("4");
    myGraph1.addNode("5");
    myGraph1.addNode("6");
    myGraph1.addNode("7");
    myGraph1.addEdge("1","2",1);
    myGraph1.addEdge("1","5",1);
    myGraph1.addEdge("1","3",1);
    myGraph1.addEdge("2","3",1);
    myGraph1.addEdge("3","4",1);
    myGraph1.addEdge("4","5",1);
    myGraph1.addEdge("5","6",1);
    myGraph1.addEdge("7","6",1);
    cout<<myGraph1.toString()<<endl<<"Colors:\n";
    auto colorsWithNodes1 = myGraph1.giveColors();
    for (auto p : colorsWithNodes1.items())
    {
        cout<<p.getValue().getFirst()<<" :";
        for (size_t i = 0; i < p.getValue().getSecond().length(); i++)
        {
            cout<<p.getValue().getSecond().getElement(i)<<" ";
        }
        cout<<'\n';
    }
    cout<<endl<<endl;
    //2 test
    graph::UndirectedGraph<int, std::string> myGraph2("BTreeDictionary", "ArraySequence", 0, "null");
    myGraph2.addNode("1");
    myGraph2.addNode("2");
    myGraph2.addNode("3");
    myGraph2.addNode("4");
    myGraph2.addNode("5");
    myGraph2.addNode("6");
    myGraph2.addNode("7");
    myGraph2.addNode("8");
    myGraph2.addNode("9");
    myGraph2.addNode("10");
    myGraph2.addEdge("3","2",1);
    myGraph2.addEdge("3","4",1);
    myGraph2.addEdge("4","5",1);
    myGraph2.addEdge("5","1",1);
    myGraph2.addEdge("1","2",1);
    myGraph2.addEdge("1","6",1);
    myGraph2.addEdge("2","7",1);
    myGraph2.addEdge("3","8",1);
    myGraph2.addEdge("4","9",1);
    myGraph2.addEdge("5","10",1);
    myGraph2.addEdge("8","6",1);
    myGraph2.addEdge("8","10",1);
    myGraph2.addEdge("10","7",1);
    myGraph2.addEdge("7","9",1);
    myGraph2.addEdge("9","6",1);
    cout<<myGraph2.toString()<<endl<<"Colors:\n";
    auto colorsWithNodes2 = myGraph2.giveColors();
    for (auto p : colorsWithNodes2.items())
    {
        cout<<p.getValue().getFirst()<<" :";
        for (size_t i = 0; i < p.getValue().getSecond().length(); i++)
        {
            cout<<p.getValue().getSecond().getElement(i)<<" ";
        }
        cout<<'\n';
    }
    cout<<endl<<endl;
    //test 3
     graph::UndirectedGraph<int, std::string> myGraph3("BTreeDictionary", "ArraySequence", 0, "null");
    myGraph3.addNode("1");
    myGraph3.addNode("2");
    myGraph3.addNode("3");
    myGraph3.addNode("4");
    myGraph3.addNode("5");
    myGraph3.addNode("6");
    myGraph3.addNode("7");
    myGraph3.addNode("8");
    myGraph3.addEdge("1","2",1);
    myGraph3.addEdge("2","3",1);
    myGraph3.addEdge("3","4",1);
    myGraph3.addEdge("4","5",1);
    myGraph3.addEdge("8","6",1);
    myGraph3.addEdge("6","7",1);
    myGraph3.addEdge("8","7",1);
    cout<<myGraph3.toString()<<endl<<"Colors:\n";
    auto colorsWithNodes3 = myGraph3.giveColors();
    for (auto p : colorsWithNodes3.items())
    {
        cout<<p.getValue().getFirst()<<" :";
        for (size_t i = 0; i < p.getValue().getSecond().length(); i++)
        {
            cout<<p.getValue().getSecond().getElement(i)<<" ";
        }
        cout<<'\n';
    }
    cout<<endl<<endl;
//test it urself
    cout<<"if u want u can test it urself! commands:\n\t addnode\n\t addedge\n\t print\n\t removenode\n\t removeedge \n\t givecolors\n";
    string answer = "";
    graph::UndirectedGraph<int, std::string> myGraph("BTreeDictionary", "ArraySequence", 0, "null");
    while (answer != "end")
    {
        cin>>answer;
        if (answer == "print")
        {
            cout<<myGraph.toString()<<'\n';
        }
        if (answer == "addnode")
        {
            string name;
            cin>>name;
            myGraph.addNode(name);
        }
        if (answer == "removenode")
        {
            string name;
            cin>>name;
            myGraph.removeNode(name);
        }
        if (answer == "addedge")
        {
            string name1,name2;
            cin>>name1>>name2;
            myGraph.addEdge(name1,name2, 1);
        }
        if (answer == "removeedge")
        {
            string name1,name2;
            cin>>name1>>name2;
            myGraph.removeEdge(name1,name2);
        }
        if (answer == "givecolors")
        {
            cout<<"Colors:\n";
            auto colorsWithNodes = myGraph.giveColors();
            for (auto p : colorsWithNodes.items())
            {
                cout<<p.getValue().getFirst()<<" :";
                for (size_t i = 0; i < p.getValue().getSecond().length(); i++)
                {
                    cout<<p.getValue().getSecond().getElement(i)<<" ";
                }
                cout<<'\n';
            }
        }
        if (answer == "checkpath")
        {
            string name1,name2;
            cin>>name1>>name2;
            cout<<myGraph.checkPath(name1,name2)<<endl;
        }
        
    }
    
    return 0;
}
