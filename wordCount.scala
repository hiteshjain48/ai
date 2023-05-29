import org.apache.spark.SparkContext;

var sc = new SparkContext();

var file = sc.textFile("words.txt").flatMap(lines => lines.split(" ")).map(word=> (word,1));

var counts = file.reduceByKey(_+_)
print(counts.count)
print(counts)
var keys = counts.keys
var sorted = keys.sortBy(x=>x,true)
sorted.collect
counts.saveAsTextFile("/home/dreamster/workspace/scala/count")
sorted.saveAsTextFile("/home/dreamster/workspace/scala/sort")
