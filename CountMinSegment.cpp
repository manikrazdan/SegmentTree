class SegTree {
private:
	vector<pair<ll,ll>> seg;
public:
	SegTree(ll n) {
		seg.resize(4*n+1);
	}
	void build(ll low,ll high,ll ind,ll arr[]) {
		if (low==high) {
			seg[ind]={arr[low],1};
			return;
		}
		ll mid=(low+high)>>1;
		build(low,mid,2*ind+1,arr);
		build(mid+1,high,2*ind+2,arr);
		pair<ll,ll> left=seg[2*ind+1],right=seg[2*ind+2];
		if (left.first==right.first) {
			seg[ind]={left.first,left.second+right.second};
		}
		else if (left.first<right.first) {
			seg[ind]=left;
		}
		else {
			seg[ind]=right;
		}
	}
	void update(ll low,ll high,ll ind,ll i,ll v) {
		if (low==high) {
			seg[ind]={v,1};
			return;
		}
		ll mid=(low+high)>>1;
		if (i<=mid) {
			update(low,mid,2*ind+1,i,v);
		}
		else {
			update(mid+1,high,2*ind+2,i,v);
		}
		pair<ll,ll> left=seg[2*ind+1],right=seg[2*ind+2];
		if (left.first==right.first) {
			seg[ind]={left.first,left.second+right.second};
		}
		else if (left.first<right.first) {
			seg[ind]=left;
		}
		else {
			seg[ind]=right;
		}
	}
	pair<ll,ll> query(ll low,ll high,ll ind,ll l,ll r) {
		if (low>r||high<l) {
			return {INT_MAX,0};
		}
		if (low>=l&&high<=r) {
			return seg[ind];
		}
		ll mid=(low+high)>>1;
		pair<ll,ll> left=query(low,mid,2*ind+1,l,r);
		pair<ll,ll> right=query(mid+1,high,2*ind+2,l,r);
		if (left.first==right.first) {
			return {left.first,left.second+right.second};
		}
		else if (left.first<right.first) {
			return left;
		}
		else {
			return right;
		}
	}
};
