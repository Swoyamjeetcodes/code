class labledbreak {
    public static void main(String[] args) {
      
        // the for loop is labeled as first
        first:
        for( int i = 1; i < 5; i++) {

            // the for loop is labeled as second
            second:
            for(int j = 1; j < 3; j ++ ) {

                System.out.println("i = " + i + "; j = " +j);
       
                // the break statement terminates the loop labeled as second   
                if ( i == 2)
                    break second;
            }
        }
    }
}