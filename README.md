# Time calculation for AC/DC functions

>This program is made with ESP-IDF V4.4.2, His goal is to measure the time the ESP take to calculate those formula.
>Used to calculate effective and mean value of a AC or a rectified Sin, in order to give VRMS values.

# How values are calculated ?


# Hardware Settings : 

    ESP32-S2, CPU clock : 80MHz
    Sampling : 1000 Hz
    Sampling Number : 1024
    Number of try : 5000 times

# Quick reminder to ckeck results :

## Cosin function :
$V_{Effective} = \frac{V_{Max}}{\sqrt{2}}$

$V_{Mean} = 0$

---
## Half-Wave Rectification :
$V_{Effective} = \frac{V_{Max}}{\pi}$

$V_{Mean} = \frac{V_{Max}}{2}$

---
## Full-Wave Rectification :
$V_{Effective} = \frac{V_{Max} \times 2}{\pi}$

$V_{Mean} = \frac{V_{Max} \times \sqrt{2}}{2}$

# Cosin Function Results :

    Caracteristics : f = 50Hz, A = 20
## Float Results
### Effective :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 14.15    | 1504
Right        | 14.11    | 2658
Trapezoidal  | 14.11    | 2599
### Mean :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 00.05    | 928
Right        | 00.00    | 1981
Trapezoidal  | 00.00    | 2038
Basic        | 00.06    | 1972
## Double Results
TODO
# Half-Wave Rectification Function Results :

    Caracteristics : f = 50Hz, A = 20
## Float Results
### Effective :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 10.03    | 1386
Right        | 09.98    | 2539
Trapezoidal  | 09.98    | 2480
### Mean :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 06.34    | 744
Right        | 05.86    | 1819
Trapezoidal  | 02.42    | 1880
Basic        | 06.24    | 1817
## Double Results
TODO