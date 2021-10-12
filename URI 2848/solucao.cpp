#include <bits/stdc++.h>
using namespace std;

int quickselect(vector<int>& nums, int k, int l, int r){
	int pivot = nums[r];
	int p = l;
	
	for(int i=l; i<r; i++)
		if(nums[i]<=pivot)
			swap(nums[p++],nums[i]);
			
	swap(nums[p],nums[r]);
	
	if(k<p) return quickselect(nums, k, l, p-1);
	else if(k>p) return quickselect(nums, k, p+1, r);
	else return nums[p];
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	
	vector<int> vetor(n);
	for(int i=0;i<n;i++){
		cin>>vetor[i];
	}
	
	int l,r,k,g,d;
	int min_k,qtd;
	int difG,difD;
	for(int i=0;i<q;i++){
		scanf("%d%d%d%d%d",&l,&r,&k,&g,&d);
		
		/*vector<int> ordenado(vetor.begin()+(l-1),vetor.begin()+(l-1)+(r-l)+1);
		sort(ordenado.begin(),ordenado.end());
		min_k = ordenado[k-1];*/
		
		/*multiset<int> ordenado(vetor.begin()+(l-1),vetor.begin()+(l-1)+(r-l)+1);
		multiset<int>::iterator it = ordenado.begin();
		advance(it,k-1);
		min_k = *it;*/
		
		vector<int> sub(vetor.begin()+(l-1),vetor.begin()+(l-1)+(r-l)+1);
		/*vector<int> minn(k,*max_element(sub.begin(),sub.end()));
		
		int lim = sub.size();
		for(int i=0;i<lim;++i){
			int dif_min = sub[i] - minn[0];
			int pos = 0;
			for(int j=1;j<k;j++){
				if(dif_min > sub[i] - minn[j]){
					dif_min = sub[i] - minn[j];
					pos = j;
				}
			}
			
			if(dif_min < 0){
				minn[pos] = sub[i];
			}
		}

		min_k = *max_element(minn.begin(),minn.end());*/
		
		//min_k = quickselect(sub, k-1, 0, sub.size()-1); 
		
		int p,pivot;
		int lqs = 0;
		int rqs = sub.size()-1;
		while(p!=k-1){
			p = lqs;
			pivot = sub[rqs];
			
			for(int i=lqs;i<rqs;i++)
				if(sub[i]<=pivot)
					swap(sub[p++],sub[i]);
			
			swap(sub[p],sub[rqs]);
			if(k-1<p) rqs=p-1;
			else if(k-1>p) lqs=p+1;
		}
		min_k = sub[k-1];
		
		qtd = 0;
		for(int i=l-1;i<r;i++)
			if(vetor[i] == min_k)
				++qtd;
		
		printf("%d %d ",min_k,qtd);
		
		difG = abs(qtd - g);
		difD = abs(qtd - d);
		
		if(difG == difD)
			printf("E\n");
		else if(difG < difD)
			printf("G\n");
		else
			printf("D\n");
	}
}
