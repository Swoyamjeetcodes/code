class A 
{
    public static void main(String args[])
    {
        String S = "   hello1234";
        String S1 = S.trim();
        String S2 = "HELLO1234";
        int a = 10;
        System.out.println(S);
        System.out.println(S1);
        System.out.println(S.length());
        System.out.println(S.isEmpty());
        System.out.println(S1);
        System.out.println(S1.concat(S));
        System.out.println(S1.join(S,S1,","));
        System.out.println(S1+S);
        System.out.println(S.subSequence(5,9));
        System.out.println(S.substring(5));
        System.out.println(S.substring(5,9));
        System.out.println(S.replace("l","t"));
        System.out.println(S.replaceFirst("l","t")); //replaces first found substring that matches
        System.out.println(S.indexOf('e'));
        System.out.println(S.indexOf("lo"));
        System.out.println(S.lastIndexOf('l'));
        System.out.println(S.charAt(5));
        System.out.println(S.contains("ep"));
        System.out.println(S.startsWith("ep"));
        System.out.println(S.endsWith("4"));
        System.out.println(S.equals(S1));
        System.out.println(S1.equalsIgnoreCase(S2));
        System.out.println(S.toUpperCase());
        System.out.println(S2.toLowerCase());
        System.out.println(S.valueOf(a));
        System.out.println(S.compareTo(S1));

        if(S.trim().length()!=0)
        {
            System.out.println(12);
        }
    }
}