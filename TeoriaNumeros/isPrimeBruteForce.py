

def is_prime(n: int) -> bool: 
    if n < 2 : 
        return False
    if n == 2: 
        return True 
    for i in range(2, n): 
        if n % i == 0: 
            return False
        return True