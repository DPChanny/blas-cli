int l_and(int a, int b) {
	if (a == 1 && b == 1) {
		return 1;
	}
	else return 0;
}

int l_or(int a, int b) {
	if (a == 1 || b == 1) {
		return 1;
	}
	else return 0;
}

int l_not(int a) {
	return !a;
}

int l_xor(int a, int b) {
	if (a == 1 || b == 1) {
		if (a == 1 && b == 1) {
			return 0;
		}
		else return 1;
	}
	else return 0;
}

int l_flip_flop(int a, int b) {
	return 0;
}