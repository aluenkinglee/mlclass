package net.wecash.util;

public class Const {
    // 无用标点符号
    public final static String[] punctuation = { "“", "”", "。", "，", "、", "：",
            " " };
    
    // 停用词，暂无
    
    public static String _getCategoryFromName(String name) {
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
}
