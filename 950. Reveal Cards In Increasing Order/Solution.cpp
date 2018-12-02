class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> result(deck.size());
        queue<int> q;
        for (int i = 0; i < deck.size(); ++i) q.push(i);
        sort(deck.begin(), deck.end());
        for (int i = 0; i < deck.size(); ++i)
        {
            result[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return result;
    }
};