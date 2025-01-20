# Assignment Report 
## Q1 (a) Running the Code for n = 4000 with Format Flags 0 and 1

**Task:**
Run the code corresponding to Question No. 6 from HW0 for `n = 4000` with the ‘format flag’ equal to 0 and then equal to 1. Report the sizes in MB of the two files that are generated.

**Results:**
- **array00400_asc.out**: size on disk = 319 MB (33,55,03,360 bytes)
- **array00400_bin.out**: size on disk = 122 MB (12,80,00,000 bytes)

## (b) Estimating the Size of the Array in Memory

**Task:**
Estimate the size of the array in memory by multiplying the size of one double (8 bytes) with the number of doubles (`n^2`) in the array. Comment on the size in memory vs size on disk for the above two files. Comment on which format is best suited for saving large data.

**Answer:**

### Estimated Size:
- Size of one `double` = 8 bytes
- Total memory required: `n * n * 8 bytes = 8 × 16,000,000 = 128,000,000 bytes = 122.0703125 MB`

### Comments:
- **Binary file (`bin`)**: The size on the disk (122.1 MB) matches exactly with the estimated size, as it stores the raw data without extra formatting.
- **ASCII file (`asc`)**: The size (319.9 MB) is significantly larger because:
  1. Conversion of binary values to human-rujeadable decimal strings.
  2. Extra characters like spaces and newline characters.
  3. Higher precision representation (15 decimal places).

### Conclusion:
- It is better to store data in a **binary file** as it requires significantly less space than ASCII and offers faster read/write operations, as no conversion is needed.
- **ASCII format** is better when data needs to be human-readable but is inefficient for large datasets due to its size and slower performance.

---

## Question 2

Given an integer `n`, we are provided with a matrix of size `n*n` and four sample vectors. We need to check if these vectors are eigenvectors of the given matrix `A`.

I am using the formula:

$$ A * \text{vector} = \lambda * \text{vector} $$

This is valid if the vector is an eigenvector.

To check, I am calculating all the lambda0, lamda1 ... lambda(n-1) and if `minLambda == maxLambda`, it means the given vector is an eigenvector and eigenValue corrosponding to that vector is Lambda (maxlamda pr minlambda) Otherwise, it is not.

The results for every vectore will be printed on the screen.

---
Thank you 
Pavankumar Shinde | CO22BTECH11008
