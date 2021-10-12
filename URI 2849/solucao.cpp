#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int>::iterator pesquisaBinaria(vector<int>& vetor, long long elemento){
	int l = 0, r = (int)vetor.size()-1;
	vector<int>::iterator it = vetor.begin();
	
	if(*it >= elemento)
		return it;
	
	int pos_metade = -1, pos_anterior = 0;
	
	while(pos_anterior != pos_metade){
		pos_anterior = pos_metade;
		pos_metade = (l+r)/2;
		
		if(elemento == *(it + pos_metade))
			return it + pos_metade;
		else if(elemento > *(it + pos_metade))
			l = pos_metade;
		else
			r = pos_metade;
	}
	
	it += pos_metade;
	vector<int>::iterator comeco = vetor.begin();
	vector<int>::iterator fim = vetor.end();

	if(it < fim && *it < elemento){
		for(;it < fim && *it < elemento; ++it);
	}
	else if(it < fim && *it > elemento){
		for(;it >= comeco && *it > elemento; --it);
		++it;
	}
	
	return it;
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	
	long long* vetor = new long long[n];
	int* pos_ord = new int[n];
	unordered_map<long long,vector<int>> num_posicoes;
	
	for(int i=0; i<n; ++i){
		scanf("%lld",vetor+i);
		pos_ord[i] = i;
		num_posicoes[vetor[i]].push_back(i);
	}
	
	auto comparar = [&vetor](int a, int b) -> bool{
		return vetor[a] < vetor[b];
	};
		
	sort(pos_ord,pos_ord+n,comparar);
	
	int l,r,k,g,d;
	for(int i=0; i<q; i++){
	scanf("%d%d%d%d%d",&l,&r,&k,&g,&d);
        --l,--r;
        
        long long kth_elemento = 0;
        for(int i=0, j=0; j<k && i<n; ++i){
		if(pos_ord[i] >= l && pos_ord[i]<= r){
			++j;
			if(j == k)
				kth_elemento = vetor[pos_ord[i]];
		}
	}

        int qtd = 0;
	vector<int>& vetor_posicoes = num_posicoes[kth_elemento];
        vector<int>::iterator it_l =  pesquisaBinaria(vetor_posicoes, l);
        vector<int>::iterator it_r =  pesquisaBinaria(vetor_posicoes, r);
        
        if(it_r < vetor_posicoes.end() && *it_r == r)
            ++it_r;
            
        qtd = it_r-it_l;
		
		printf("%lld %d ",kth_elemento,qtd);
		
		int difG,difD;
		difG = abs(qtd - g);
		difD = abs(qtd - d);
		
		if(difG == difD)
			printf("E\n");
		else if(difG < difD)
			printf("G\n");
		else
			printf("D\n");
	}

	delete []vetor;
	delete []pos_ord;
}
