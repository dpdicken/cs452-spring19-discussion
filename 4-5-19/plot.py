from matplotlib import pyplot as plt # may have to pip install this

data = {
	"FIFO" :{
		"pageFaults" : [100, 150, 200],
		"numberFrames" : [1, 32, 64]
	},
	"OPT" : {
		"pageFaults" : [200, 100, 10],
		"numberFrames" : [1, 32, 64]
	}
}

fig = plt.figure()
fig.suptitle("My Graph Title!")
plt.xlabel("Page faults")
plt.ylabel("Number frames")


for alg in data.keys():
	x = data[alg]["pageFaults"]
	y = data[alg]["numberFrames"]
	line, = plt.plot(x, y)
	line.set_label(alg)

plt.legend(loc="upper right")
fig.savefig("./graph.png")
