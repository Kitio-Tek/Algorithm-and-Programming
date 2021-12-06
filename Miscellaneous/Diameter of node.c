int tree_diameter(node_t *r){
	int count=0;

	tree_diameterR(r,&count);

	return count;
}

void tree_diameterR(node_t *r,int *count){
	int d=0;

	if(r==NULL){
		return ;
	}
	 
	d=height(r->left)+height(r->right);
	

	if(d>*count) *count=d;
	

	tree_diameterR(r->left,count);
	tree_diameterR(r->right,count);

}

int height(node_t *r){
	int r=0,f=0;
	if(r==NULL)
		return 0;
	r=height(r->right);
	f=height(r->left);

	if(r>f) return r+1;

	return f+1;



}