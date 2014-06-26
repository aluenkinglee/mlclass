package net.wecash.classifier;

import java.io.DataInputStream;
import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import net.wecash.util.Const;
import net.wecash.util.Instance;
import net.wecash.util.Variable;

public class NaiveBayes {

    // 记录每个类别下出现的文档数量, 用于计算P(Category)使用
    Variable VARIABLE = new Variable();

    // 词语在所有类别中的总数量
    Map<String, Integer> TERM_TOTAL_COUNT = new HashMap<String, Integer>();

    public static void main(String[] args) throws IOException {
        // 拿训练集数据进行训练，2720个文件
        // trainSamples();

        // 测试测试集准确性332个文件
        int total = 0;
        int TP = 0;
        NaiveBayes classifier = new NaiveBayes();

        classifier.load(new File("result.dat"));

        System.out.println("testing the accracy");
        File list = new File("./data-testing-set");
        Instance inst = null;
        for (File f : list.listFiles()) {
            total++;
            inst = new Instance(f);
            // 预测实例的类别
            String result = inst.getCategory();
            // 从文件名得到实例的类别
            String category = Const._getCategoryFromName(f.getName());
            System.out.print("文件名：" + f.getName() + ",真实结果：" + category);
            System.out.println(",预测结果" + result);
            if (result.equals(category)) {
                TP++;
            }
        }
        System.out.println("total number:" + total);
        System.out.println("true precison:" + TP);
        System.out.println("precision:" + TP / total);
        // Instance doc = new Instance(new File("./data-test/1sport.txt"));
        // System.out.println(classifier.getCategory(doc));
        // doc = new Instance(new File("./data-test/2sport.txt"));
        // System.out.println(classifier.getCategory(doc));
        // doc = new Instance(new File("./data-test/3business.txt"));
        // System.out.println(classifier.getCategory(doc));
        // doc = new Instance(new File("./data-test/4business.txt"));
        // System.out.println(classifier.getCategory(doc));

    }

    public static void test() {
        // 训练数据
        // NaiveBayes.trainSamples(directory, outfile);
        // 分类
        // NaiveBayes nb = new NaiveBayes();
        // nb.load(outfile);
        // Instance instance = new Instance(new File(pathname));
        // nb.getCategory(instance);
    }

    /**
     * 训练目录下的样本集合
     * 
     * @throws IOException
     */
    public static void trainSamples() throws IOException {
        NaiveBayes classifier = new NaiveBayes();
        File flist = new File("./data-trainning-set");
        for (File f : flist.listFiles()) {
            classifier.training(new Instance(f));
        }
        classifier.save(new File("result.dat"));
        System.out.println("Trainning finished");
    }

    /**
     * specify the training dataset directory, and store result in the outfile
     * 
     * @param directory
     * @param result
     * @throws IOException
     */
    public static void trainSamples(String directory, String outfile)
            throws IOException {
        NaiveBayes classifier = new NaiveBayes();
        File flist = new File(directory);
        for (File f : flist.listFiles()) {
            classifier.training(new Instance(f));
        }
        classifier.save(new File(outfile));
        System.out.println("Trainning finished");
    }

    /**
     * 判断该实例所属的类别category
     * 
     * @param doc
     * @return
     */
    public String getCategory(Instance doc) {
        Collection<String> categories = VARIABLE.getCategories();
        System.out.println(categories);
        double best = Double.NEGATIVE_INFINITY;
        String bestName = null;
        for (String c : categories) {
            double current = getProbability(c, doc);
            System.out.println(c + ":" + current);
            if (best < current) {
                best = current;
                bestName = c;
            }
        }
        return bestName;
    }

    /**
     * 计算P（C)=该类型文档总数/文档总数，返回的数对数值
     * 
     * @param category
     * @return
     */
    public double getCategoryProbability(String category) {
        return Math.log(VARIABLE.getDocCount(category) * 1.0f
                / VARIABLE.getDocCount());
    }

    /**
     * 计算P(feature|cateogry),返回的是取对数后的数值
     * 
     * @param feature
     * @param category
     * @return
     */
    public double getFeatureProbability(String feature, String category) {
        int m = VARIABLE.getFeatureCount();
        return Math.log((VARIABLE.getDocCount(feature, category) + 1.0)
                / (VARIABLE.getDocCount(category) + m));
    }

    /**
     * 计算给定实例文档属于指定类别的概率，返回的是取对数后的数值
     * 
     * @param category
     * @param doc
     * @return
     */
    public double getProbability(String category, Instance doc) {
        double result = getCategoryProbability(category);
        for (String feature : doc.getWords()) {
            if (VARIABLE.containFeature(feature)) {
                result += getFeatureProbability(feature, category);
            }
        }
        return result;
    }

    /**
     * 加载训练结果
     * 
     * @param file
     * @throws IOException
     */
    public void load(File file) throws IOException {
        DataInputStream in = new DataInputStream(new FileInputStream(file));
        VARIABLE = Variable.read(in);
    }

    /**
     * 保存训练结果
     * 
     * @throws IOException
     */
    void save(File file) throws IOException {
        DataOutput out = new DataOutputStream(new FileOutputStream(file));
        VARIABLE.write(out);
    }

    /**
     * 训练一篇文档
     * 
     * @param doc
     */
    public void training(Instance doc) {
        VARIABLE.addInstance(doc);
    }

}
