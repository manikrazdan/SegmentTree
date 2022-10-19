class SegTree {
private:
	vector<ll> seg;
public:
	SegTree(ll n) {
		seg.resize(4*n+1,0);
	}
	void build(ll low,ll high,ll ind,ll arr[]) {
		if (low==high) {
			seg[ind]=arr[low];
			return;
		}
		ll mid=(low+high)>>1;
		build(low,mid,2*ind+1,arr);
		build(mid+1,high,2*ind+2,arr);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}
	void update(ll low,ll high,ll ind,ll i,ll v) {
		if (low==high) {
			seg[ind]=v;
			return;
		}
		ll mid=(low+high)>>1;
		if (i<=mid) {
			update(low,mid,2*ind+1,i,v);
		}
		else {
			update(mid+1,high,2*ind+2,i,v);
		}
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}
	ll query(ll low,ll high,ll ind,ll l,ll r) {
		if (low>r||high<l) {
			return 0;
		}
		if (low>=l&&high<=r) {
			return seg[ind];
		}
		ll mid=(low+high)>>1;
		ll left=query(low,mid,2*ind+1,l,r);
		ll right=query(mid+1,high,2*ind+2,l,r);
		return left+right;
	}
};
