import math

def is_prime(n: int) -> bool: 
    if n < 2 : 
        return False
    if n == 2: 
        return True 
    if n % 2 == 0: 
        return False
    limit = int(math.sqrt(n)) + 1
    for i in range(3, limit, 2): 
        if n % i == 0: 
            return False
    return True