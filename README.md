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
$V_{Effective} = \frac{V_{Max}}{2}$

$V_{Mean} = \frac{V_{Max}}{\pi}$

---
## Full-Wave Rectification :
$V_{Effective} = \frac{V_{Max} \times \sqrt{2}}{2}$

$V_{Mean} = \frac{V_{Max} \times 2}{\pi}$


# Cosin Function Results :

    Caracteristics : f = 50Hz, A = 20
## Float Results
### Effective :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 14.15    | 1505
Right        | 14.14    | 1505
Trapezoidal  | 14.15    | 1510
Calculs      | 14.14    | By Hands
### Mean :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 00.05    | 928
Right        | 00.06    | 928
Trapezoidal  | 00.06    | 932
Basic        | 00.07    | 899
## Double Results
TODO
# Half-Wave Rectification Function Results :

    Caracteristics : f = 50Hz, A = 20
## Float Results
### Effective :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 10.03    | 1386
Right        | 10.02    | 1386
Trapezoidal  | 10.03    | 1391
Calculs      | 10.00    | By Hands
### Mean :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 06.34    | 744
Right        | 06.33    | 743
Trapezoidal  | 06.35    | 747
Basic        | 06.35    | 715
Calculs      | 06.36    | By Hands
## Double Results
TODO

# Full-Wave Rectification Function Results :

    Caracteristics : f = 50Hz, A = 20
## Float Results
### Effective :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 13.83    | 1496
Right        | 13.82    | 1496
Trapezoidal  | 13.82    | 1501
Calculs      | 14.14 ?? | By Hands
### Mean :
Method       | Result   | Time (us)
-------------|----------|----------
Left         | 12.31    | 754
Right        | 12.31    | 754
Trapezoidal  | 12.31    | 757
Basic        | 12.32    | 725
Calculs      | 12.73    | By Hands
## Double Results
TODO