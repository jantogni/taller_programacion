#include <iostream>
#include <vector>
#include <string>

#define NVALUES 13
#define NSUITS 4
#define NCARDS 52
#define NSHUFFLES 100

using namespace std;

vector<string> values(NVALUES);
vector<string> suits(NSUITS);

int shuffles[NSHUFFLES][NCARDS];
int deck[NCARDS];

void read_shuffles(int n_shuff) {
	int i,j;

        for(i=0; i<n_shuff; i++) {
                for (j=0; j<NCARDS; j++) {
                        cin >> shuffles[i][j];
                }
        }
}

void shuffle_deck(int s_id) {
        int tmpdeck[NCARDS];
	int i;

        for (i=0; i<NCARDS; i++) {
                tmpdeck[i] = deck[shuffles[s_id][i] - 1];
        }
        for (i=0; i<NCARDS;i++) {
                deck[i] = tmpdeck[i];
        }
}

int main () {
	values[0] = "2"; values[1] = "3"; values[2] = "4"; values[3] = "5"; values[4] = "6"; values[5] = "7"; values[6] = "8"; 
	values[7] = "9"; values[8] = "10"; values[9] = "Jack"; values[10] = "Queen"; values[11] = "King"; values[12] = "Ace";
	suits[0] = "Clubs"; suits[1] = "Diamonds"; suits[2] = "Hearts"; suits[3] = "Spades";

        int nCases;
        int nShuffles;
        int shuffle;
        int i,p,j,k;

        cin >> nCases;
                
        for (i=0; i<nCases; i++) {      
                cin >> nShuffles;
                        
                for (p=0; p<NCARDS; p++) {
                        deck[p] = p;
                }
                
                read_shuffles(nShuffles);
                
                for (j=0; j<nShuffles; j++) {
                        cin >> shuffle;
                        shuffle_deck(shuffle - 1);
                }

                for (k=0; k<NCARDS; k++) {
                        cout << values[deck[k] % NVALUES] << " of " << suits[deck[k] / NVALUES] << endl;
                }
                if (i < (nCases - 1)) {
                        cout << endl;
                }
        }
        
}
