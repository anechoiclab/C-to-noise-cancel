# sine.csv をグラフにする（記事用の画像づくり）
# 実行: python3 plot_sine.py  → sine.png が保存される
import csv
import matplotlib.pyplot as plt
 
t, x = [], []
with open("sine.csv") as f:
    reader = csv.DictReader(f)
    for row in reader:
        t.append(float(row["t"]))
        x.append(float(row["x"]))
 
plt.figure(figsize=(8, 3))
plt.plot(t, x)
plt.xlabel("Time [s]")
plt.ylabel("Amplitude")
plt.title("5 Hz sine wave (fs = 1000 Hz)")
plt.grid(True)
plt.tight_layout()
plt.savefig("sine.png", dpi=150)
print("sine.png を保存しました")