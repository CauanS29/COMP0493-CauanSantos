def gcd_extended(a, b):
    if a == 0:
        return b, 0, 1
    
    mdc, x1, y1 = gcd_extended(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    
    return mdc, x, y

def inverso_modular(a, m):
    if a < 0:
        a = a % m  
    
   
    mdc, x, y = gcd_extended(a, m)
    
    
    if mdc != 1:
        return None
    else:
        
        return x % m
