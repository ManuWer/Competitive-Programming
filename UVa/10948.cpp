#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int _tam_crivo;
bitset<10000010> bs;
vector<int> primos;

// Pre-processamento: gerar primos ≤ 10.000.000 pelo Crivo de Eratostenes

void crivo(long long int limite) { // cria lista de primos em [0..limite]
	_tam_crivo = limite + 1; // + 1 para incluir limite
	bs.reset(); bs.flip(); // todos valendo true
	bs.set(0, false); bs.set(1,false); // exceto indices 0 e 1
	for (long long int i = 2; i <= _tam_crivo; i++)
		if (bs.test((size_t)i)) {
		//corta todos os multiplos de i comecando de i*i
			for (long long int j = i*i; j <= _tam_crivo; j += i)
				bs.set((size_t)j, false);
			primos.push_back((int)i); // adiciona na lista de primos
		}
}

int main() {
	crivo(1000000);
	int n;

	while(cin >> n && n!=0) {
		vector< pair<int,int> > ways;
		vector<int>::iterator it = upper_bound(primos.begin(),primos.end(),n);

		for(vector<int>::iterator i=primos.begin();i!=it;i++) {
			vector<int>::iterator j = lower_bound(primos.begin(),primos.end(),n-*i);
			if((*i)+(*j)==n) ways.push_back(make_pair(*i,*j));
		}

		if(!ways.empty()) {
			pair<int,int> best = ways[0];
			int dif = abs(best.first - best.second); 
			int a;
			for(int i=1;i<ways.size();i++) {
				a = abs(ways[i].first - ways[i].second);
				if(a>dif) {
					dif = a;
					best = ways[i];
				}
			}
	
			cout << n << ":\n" << best.first << "+" << best.second << endl;
		} else cout << n << ":\n" << "NO WAY!\n";
	}
	
	return 0;
}