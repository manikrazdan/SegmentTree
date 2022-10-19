class Node {
private:
	ll s,pf,sf,x;
public:
	Node(ll a,ll b,ll c,ll d) {
		x=a;
		pf=b;
		sf=c;
		s=d;
	}
	ll sum() {return s;}
	ll prefix() {return pf;}
	ll suffix() {return sf;}
	ll ans() {return x;}
};

class SegTree {
private:
	vector<Node*> seg;
public:
	SegTree(ll n) {
		seg.resize(4*n+1);
	}
	void build(ll low,ll high,ll ind,ll arr[]) {
		if (low==high) {
			if (arr[low]>0) {
				seg[ind]=new Node(arr[low],arr[low],arr[low],arr[low]);
			}
			else {
				seg[ind]=new Node(0,0,0,arr[low]);
			}
			return;
		}
		ll mid=(low+high)>>1;
		build(low,mid,2*ind+1,arr);
		build(mid+1,high,2*ind+2,arr);
		Node *left=seg[2*ind+1],*right=seg[2*ind+2];
		ll a=max({left->ans(),right->ans(),left->suffix()+right->prefix()});
		ll b=max(left->prefix(),left->sum()+right->prefix());
		ll c=max(right->suffix(),right->sum()+left->suffix());
		ll d=seg[2*ind+1]->sum()+seg[2*ind+2]->sum();
		seg[ind]=new Node(a,b,c,d);
	}
	void update(ll low,ll high,ll ind,ll i,ll v) {
		if (low==high) {
			if (v>0) {
				seg[ind]=new Node(v,v,v,v);
			}
			else {
				seg[ind]=new Node(0,0,0,v);
			}
			return;
		}
		ll mid=(low+high)>>1;
		if (i<=mid) {
			update(low,mid,2*ind+1,i,v);
		}
		else {
			update(mid+1,high,2*ind+2,i,v);
		}
		Node *left=seg[2*ind+1],*right=seg[2*ind+2];
		ll a=max({left->ans(),right->ans(),left->suffix()+right->prefix()});
		ll b=max(left->prefix(),left->sum()+right->prefix());
		ll c=max(right->suffix(),right->sum()+left->suffix());
		ll d=seg[2*ind+1]->sum()+seg[2*ind+2]->sum();
		seg[ind]=new Node(a,b,c,d);
	}
	ll maxSum() {
		return seg[0]->ans();
	}
};
