import random
import numpy as np
rng_seed = 77154230262421188038474627867692123242
random_seed = 317141540767680279119930906445496212648
random.seed(random_seed)
rng = np.random.default_rng(seed=rng_seed)
with open('test 1', 'w') as f:
    array = [random.randint(-1000000000,1000000000) * rng.random() for __ in range(1000000)]
    array = np.sort(array)
    for num in array:
        f.write(str(num) + ' ')

with open('test 2', 'w') as f:
    array = [random.randint(-1000000000,1000000000) * rng.random() for __ in range(1000000)]
    array = np.sort(array)
    for num in array:
            f.write(str(num) + ' ')

for _ in range(3,11,1):
    file_name = "test " + str(_) 
    with open(file_name, 'w') as f:
        array = [random.randint(-1000000000,1000000000) * rng.random() for __ in range(1000000)]
        for num in array:
            f.write(str(num) + ' ')