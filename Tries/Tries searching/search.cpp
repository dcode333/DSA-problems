#include <bits/stdc++.h>
using namespace std;

/**  Trie Node  **/
struct Node
{
    Node *characters[128];
    bool isCompleted;
    string makeWord;

    bool isPresent(int ch) // Checking if characters of current Node is non-empty
    {
        return (characters[ch] != NULL);
    }

    void insertNode(int ch, Node *node) // Inserting a Node at given position
    {
        characters[ch] = node;
    }

    Node *getNode(int ch)
    {
        return characters[ch];
    }

    void completed() // marking the current node as a valid word
    {
        isCompleted = true;
    }
};

/**  Class Trie  **/
class Trie
{
private:
    Node *root;

public:
    Trie() // Default constructor
    {
        root = new Node();
        root->isCompleted = false; // Every new node will be an incomplete word
        root->makeWord = "";
    }

    Node *getRoot()
    {
        return root;
    }

    /*---- PART 1----*/
    void insert(string query)
    {
        Node *node = root;
        string word = "";

        for (int i = 0; i < query.size(); i++)
        {
            word += query[i];
            if (!node->isPresent(query[i]))
                node->insertNode(query[i], new Node());

            node->makeWord = word;
            node = node->getNode(query[i]);
        }

        node->makeWord = query; // check
        node->completed();
    }

    void subSearch(Node *node, vector<string> &words)
    {
        if (node == NULL)
            return;

        if (node->isCompleted)
            words.push_back(node->makeWord);

        for (int i = 0; i < 128; i++)
        {
            if (node->characters[i] != NULL)
                subSearch(node->characters[i], words);
        }
    }

    /*---- PART 3 ----*/
    vector<string> recommendationSearch(string input)
    {
        Node *node = root;
        stack<Node *> inputNodes;
        vector<string> recommendations;

        // Edge case: while the starting is space keep trimming
        while (input[0] == ' ')
            input = input.substr(1);

        // Deapth First Searching
        // storing all possible nodes of each character of input string
        for (int i = 0; i < input.size(); i++)
        {
            if (node->isPresent(input[i]))
            {
                inputNodes.push(node);
                node = node->getNode(input[i]);
            }
            else
                break;
        }

        inputNodes.push(node);

        // searching for top three recommendations according to input
        for (int i = 0; i < inputNodes.size(); i++)
        {
            subSearch(inputNodes.top(), recommendations);
            if (recommendations.size() >= 3)
                break;

            inputNodes.pop();
        }

        return recommendations;
    }

    /*---- PART 2----*/
    void autoComplete(string input)
    {
        string subInput = input;
        int inputLength = input.size() - 1;

        // manipulating the input
        while (input[input.size() - 1] == ' ')
            input.pop_back();

        while (input[inputLength] != ' ')
        {
            if (inputLength == 0)
                break;
            inputLength--;
        }

        subInput = subInput.substr(0, inputLength);

        if (inputLength != 0)
            input = input.substr(inputLength + 1);

        vector<string> topRecommendations = recommendationSearch(input);

        cout << "Your options are: \n";

        for (int i = 0; i < 3; i++)
            cout << subInput << " " << topRecommendations[i] << endl;
    }
};

int main()
{

    Trie *trie = new Trie();
    ifstream inFile;
    string text;

    cout << "\n\nInserting words from file into Trie...\n";
    inFile.open("Dictionary.txt");
    if (!inFile)
    {
        cout << "Unable to open Dictionary.txt";
        exit(1); // terminate with error
    }

    while (getline(inFile, text))
        trie->insert(text);

    cout << "All words inserted into the Trie Successfully !!\n";
    inFile.close();

    char search;
    do
    {
        cout << "\nPlease choose a search option from following: \n";
        cout << "(1) Recommendation Search\n(2) Auto complete\n";
        cin >> search;
    } while (search != '1' && search != '2');

    string query;
    cout << "\nType your query: \n";
    cin.ignore();
    getline(cin, query);

    if (search == '2')
        trie->autoComplete(query);
    if (search == '1')
    {
        cout << "Do you mean: \n";
        vector<string> topRecommendations = trie->recommendationSearch(query);
        for (int i = 0; i < 3; i++)
            cout << topRecommendations[i] << endl;
    }

    return 0;
}
