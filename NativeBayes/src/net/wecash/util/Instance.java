package net.wecash.util;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * @author kinglee
 *
 */
/**
 * @author kinglee
 *
 */
public class Instance {
    // 文档类别
    private String category;
    // 文档内容，采用的Bernoulli朴素贝叶斯分布
    private Set<String> bag = new HashSet<String>();
    // 文档内容，采用Multinomial朴素贝叶斯分布
    private Map<String, Integer> wordCountMap = new HashMap<String, Integer>();

    public Instance() {
    }

    /**
     * 通过分析file的名字，判断其类别，完善文档内容（bag 和 wordCountMap）
     * @param f
     */
    public Instance(File f) {
        String name = f.getName();
        String category = _getCategoryFromName(name);
        if (category != null) {
            this.category = category;
        }
        try {
            Scanner in = new Scanner(f);
            while (in.hasNext()) {
                String word = in.next().trim();
                int i = 0;
                boolean flag = false;
                for (; i < Const.punctuation.length; i++) {
                    if (word.equals(Const.punctuation[i])) {
                        flag = true;
                    }
                }
                if (flag == false) {
                    bag.add(word);
                    incWordCount(word);
                }
            }
            in.close();
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    /**
     * 根据指定的category和file,生成bag和wordCountMap
     * @param category
     * @param f
     */
    public Instance(String category, File f) {
        this.category = category;
        try {
            Scanner in = new Scanner(f);
            while (in.hasNext()) {
                String word = in.next().trim();
                int i = 0;
                boolean flag = false;
                for (; i < Const.punctuation.length; i++) {
                    if (word.equals(Const.punctuation[i])) {
                        System.out.println(word);
                        flag = true;
                    }
                }
                if (flag == false) {
                    bag.add(word);
                    incWordCount(word);
                }
            }
            in.close();
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public void incWordCount(String word) {
        if (wordCountMap.containsKey(word)) {
            wordCountMap.put(word, wordCountMap.get(word) + 1);
        } else {
            wordCountMap.put(word, 1);
        }
    }

    public int getWordCount(String word) {
        if (wordCountMap.containsKey(word)) {
            return wordCountMap.get(word);
        } else {
            return 0;
        }
    }

    /**根据文件名字即name判断其类型
     * @param name
     * @return
     */
    private String _getCategoryFromName(String name) {
        if (name.contains("auto")) {
            return "auto";
        }
        if (name.contains("business")) {
            return "business";
        }
        if (name.contains("sport")) {
            return "sport";
        }
        return null;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public String getCategory() {
        return this.category;
    }

    /** 返回Bernoulli形式下的词包{word}
     * @return Set<String> bag
     */
    public Set<String> getWords() {
        return this.bag;
    }

    /** 返回Multinomial形式下的词包{<word:cnt>}
     * @returnMap<String, Integer> wordCountMap
     */
    public Map<String, Integer> getWordCount() {
        return this.wordCountMap;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        /*
         * File f = new File("./data-class/1business.seg.cln.txt");
         * System.out.println(f.getName()); Instance instance = new Instance(f);
         * System.out.println(instance.getCategory());
         * System.out.println(instance.getWords());
         */
        File flist = new File("./data-class");
        File[] files = flist.listFiles();
        Set<String> WORDBAG = new HashSet<String>();
        for (int i = 0; i < files.length; i++) {
            Instance ins = new Instance(files[i]);
            Set<String> temp = ins.getWords();
            WORDBAG.addAll(temp);
        }
        try {
            PrintStream out = new PrintStream("WORDBAG.txt");
            Iterator<String> it = WORDBAG.iterator();
            while (it.hasNext()) {
                String word = it.next();
                out.println(word);
            }
            out.close();
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }

}
