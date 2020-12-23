package customer3;

public interface PublicConstants {
	//MENU
	public static final int MENU_NUM = 8;
	public static final int POINT_MENU_NUM = 4;
	public static final int DELETE_CUSTOMER_MENU_NUM = 3;
	public static final int PRINT_CUSTOMER_LIST = 0;
	public static final int REGISTER_NEW_CUSTOMER = 1;
	public static final int MODIFY_CUSTOMER_INFO = 2;
	public static final int MODIFY_CUSTOMER_POINT = 3;
	public static final int LOOKUP_CUSTOMER_POINT = 4;
	public static final int DELETE_CUSTOMER = 5;
	public static final int EXIT = 6;
	
	//MODIFY MENU
	public static final int CUSTOMER_ID =0;
	public static final int CUSTOMER_PW =1;
	public static final int CUSTOMER_NAME =2;
	public static final int PHONE_NUM = 3;
	public static final int GENDER=4;
	public static final int POINT = 5;
	
	//POINT MENU
	public static final int CUSTOMERS_POINT =1;
	public static final int CUSTOMER_POINT =2;
	public static final int GENDER_AVG_POINT =3;
	
	//DELETE MENU
	public static final int CUSTOMER_DELETE = 1;
	public static final int ALL_CUSTOMER_DELETE = 2;
	
	//MAIN TITLE
	public static final String TITLE = "\\t### Customer Management Program ###\\n";
	public static final String[] MENU = {"## 0. �� ��� ���\n",
										 "## 1. �ű� �� ���\n",
										 "## 2. �� ���� ����\n",
										 "## 3. �� ����Ʈ ����\n",
										 "## 4. �� ����Ʈ ��ȸ\n",
										 "## 5. �� ����\n",
										 "## 6. ���α׷� ����\n",
										 ">> Input : "}; 
	public static final String[] LOOKUP_POINT_MENU = {"## 1. ��ü������Ʈ ���\n",
														"## 2. ������Ʈ ���\n",
														"## 3. ���� ����Ʈ��� ���\n",
														">> input : "};
	public static final String[] DELETE_CUSTOMER_MENU = {"##1. �� ����\n",
														"##2. ��ü �� ����\n",
														">> input : "};
	
	//MSG
	public static final String INT_MISMATCH_EXCEPT_MSG = "�߸��Է��߽��ϴ�!! ������ �ٽ� �Է����ּ���.";
	public static final String NO_EXIST_CUSTOMER_MSG = "�� ����� �����ϴ�!!";
	public static final String MODIFY_CUSTOMER_MSG = ">> �����ϰ� ���� ������ id�� �Է��ϼ��� : ";
	public static final String REGISTER_CUSTOMER_MSG = ">> ����ϰ� ���� ������ id�� �Է��ϼ��� : ";
	public static final String SEARCH_CUSTOMER_MSG = ">> ��ȸ�� ���ϴ� ������ �� ��ȣ�� �Է��ϼ��� : ";
	public static final String DELETE_CUSTOMER_MSG = ">> ������ ���ϴ� ������ �� ��ȣ�� �Է��ϼ��� : ";
	public static final String ID_OR_PW_FAILED = "���̵� �Ǵ� �н����尡 Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���.";
	public static final String CUSTOMER_ID_OVERLAP_MSG = "�̹� �ִ� ���̵��Դϴ�. �ٽ� �Է����ּ���.";
	public static final String CUSTOMER_ID_ENTER_MSG = "���̵� �Է����ּ��� >> ";
	public static final String CUSTOMER_PW_ENTER_MSG = "��й�ȣ�� �Է����ּ��� >> ";
	public static final String CUSTOMER_PW_CHECK_MSG = "��й�ȣ�� �ٽ� �Է����ּ��� >>";
	public static final String CUSTOMER_NAME_ENTER_MSG = "�̸��� �Է����ּ��� >> ";
	public static final String CUSTOMER_PN_ENTER_MSG = "�ڵ�����ȣ�� �Է����ּ��� >> ";
	public static final String CUSTOMER_GENDER_ENTER_MSG = "������ �Է����ּ��� (��/��)>> ";
	public static final String CUSTOMER_POINT_ENTER_MSG = "������ ����Ʈ�� �Է����ּ��� >> ";
	public static final String UPDATE_CUSTOMER_ATTRIBUTE = "������ �Ӽ��� �������ּ��� >>";
	public static final String UPDATE_CUSTOMER_VALUE = "������ ���� �Է����ּ��� >>";
	public static final String UPDATE_CUSTOMER_POINT = "������ ����Ʈ�� �Է����ּ��� >>";
	public static final String TAP = "\t";
	public static final String PASSWD_MISMATCH_MSG = "��й�ȣ�� ���� �ٸ��ϴ�.";
	public static final String NOT_FOUND_CUSTOMER_ID_MSG = "���̵� ã�� �� �����ϴ�.";
	public static final String NOT_MATCH_GENDER_MSG = "������ �ٽ� �Է����ּ���. ";
	public static final String CHK_FAILED = "��ü�������� ����մϴ�. ";
	public static final String ALL_DELETE_CHK_MSG = "���� ��ü���� �����Ͻðڽ��ϱ�? ������ ���ϸ� '�����ϰڽ��ϴ�'�� �Է����ּ���.";
	
	public static final String MALE = "��";
	public static final String FEMALE = "��";
	//DB
	public static final String DB_CUSTOMER_TABLE_NAME = "CUSTOMER_TABLE";
	public static final String DB_CUSTOMER_TABLE_ATTRIBUTE[] ={ "CUSTOMER_ID",
														    "CUSTOMER_PW",
														    "CUSTOMER_NAME",
														   	"PHONE_NUM",
														   	"GENDER",
															"POINT_"};
	public static final String DB_LOGIN_ID_MSG = "ORACLE ID >>";
	public static final String DB_LOGIN_PW_MSG = "ORACLE PW >>";
	public static final String DB_CONN_FAILED_MSG = "DATABASE ���ῡ �����߽��ϴ�. �ٽ� �õ����ּ���.";
	public static final String DB_CONN_MSG = "DATABASE ���ῡ �����߽��ϴ�.";
}