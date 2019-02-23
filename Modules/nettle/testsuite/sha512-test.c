#include "testutils.h"

void
test_main(void)
{
  test_hash(&nettle_sha512, SDATA("abc"),
	    SHEX("ddaf35a193617aba cc417349ae204131"
		 "12e6fa4e89a97ea2 0a9eeee64b55d39a"
		 "2192992a274fc1a8 36ba3c23a3feebbd"
		 "454d4423643ce80e 2a9ac94fa54ca49f"));
  
  test_hash(&nettle_sha512,
	    SDATA("abcdefghbcdefghicdefghijdefg"
		  "hijkefghijklfghijklmghijklmn"
		  "hijklmnoijklmnopjklmnopqklmn"
		  "opqrlmnopqrsmnopqrstnopqrstu"),
	    SHEX("8e959b75dae313da 8cf4f72814fc143f"
		 "8f7779c6eb9f7fa1 7299aeadb6889018"
		 "501d289e4900f7e4 331b99dec4b5433a"
		 "c7d329eeb6dd2654 5e96e55b874be909"));

  /* NESSIE, Set 1, vector #6 */
  test_hash(&nettle_sha512,
	    SDATA("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		  "abcdefghijklmnopqrstuvwxyz"
		  "0123456789"),
	    SHEX("1E07BE23C26A86EA37EA810C8EC78093"
		 "52515A970E9253C26F536CFC7A9996C4"
		 "5C8370583E0A78FA4A90041D71A4CEAB"
		 "7423F19C71B9D5A3E01249F0BEBD5894"));
  
  /* NESSIE, Set 1, vector #7 */
  test_hash(&nettle_sha512,
	    SDATA("1234567890123456789012345678901234567890"
		  "1234567890123456789012345678901234567890"),
	    SHEX("72EC1EF1124A45B047E8B7C75A932195"
		 "135BB61DE24EC0D1914042246E0AEC3A"
		 "2354E093D76F3048B456764346900CB1"
		 "30D2A4FD5DD16ABB5E30BCB850DEE843"));

  /* Variants longer than one block (128 bytes), to test varying alignment. */
  test_hash(&nettle_sha512,
	    SDATA("ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		  "abcdefghijklmnopqrstuvwxyz"
		  "0123456789"
		  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		  "abcdefghijklmnopqrstuvwxyz"
		  "0123456789"
		  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		  "abcdefghijklmnopqrstuvwxyz"
		  "0123456789"),
	    SHEX("5338370f5655f4da14572d4fb471539b"
		 "201485ecfb3d3204048dc6b83e61fab5"
		 "05bcbbd73e644a1a5d159a32a0889cf3"
		 "c9591b69b26d31be56c68838ce3cd63d"));
  test_hash(&nettle_sha512,
	    SDATA("1234567890123456789012345678901234567890"
		  "1234567890123456789012345678901234567890"	    
		  "1234567890123456789012345678901234567890"
		  "1234567890123456789012345678901234567890"	    
		  "1234567890123456789012345678901234567890"
		  "1234567890123456789012345678901234567890"	    
		  "1234567890123456789012345678901234567890"
		  "1234567890123456789012345678901234567890")	    ,
	    SHEX("33f8901b053e4cc677d3cb4122d96ad9"
		 "b96b13bf76194cf962488bb4de4998a7"
		 "1455cb31582db527adf77a485b81cf5b"
		 "722a5e8638eb6be487400f3aec006e7c"));

  /* Additional test vectors, from Daniel Kahn Gillmor */
  test_hash(&nettle_sha512, SDATA(""),
	    SHEX("cf83e1357eefb8bd f1542850d66d8007"
		 "d620e4050b5715dc 83f4a921d36ce9ce"
		 "47d0d13c5d85f2b0 ff8318d2877eec2f"
		 "63b931bd47417a81 a538327af927da3e"));
  test_hash(&nettle_sha512, SDATA("a"),
	    SHEX("1f40fc92da241694 750979ee6cf582f2"
		 "d5d7d28e18335de0 5abc54d0560e0f53"
		 "02860c652bf08d56 0252aa5e74210546"
		 "f369fbbbce8c12cf c7957b2652fe9a75"));
  test_hash(&nettle_sha512, SDATA("38"),
	    SHEX("caae34a5e8103126 8bcdaf6f1d8c04d3"
		 "7b7f2c349afb705b 575966f63e2ebf0f"
		 "d910c3b05160ba08 7ab7af35d40b7c71"
		 "9c53cd8b947c9611 1f64105fd45cc1b2"));
  test_hash(&nettle_sha512, SDATA("message digest"),
	    SHEX("107dbf389d9e9f71 a3a95f6c055b9251"
		 "bc5268c2be16d6c1 3492ea45b0199f33"
		 "09e16455ab1e9611 8e8a905d5597b720"
		 "38ddb372a8982604 6de66687bb420e7c"));
  test_hash(&nettle_sha512, SDATA("abcdefghijklmnopqrstuvwxyz"),
	    SHEX("4dbff86cc2ca1bae 1e16468a05cb9881"
		 "c97f1753bce36190 34898faa1aabe429"
		 "955a1bf8ec483d74 21fe3c1646613a59"
		 "ed5441fb0f321389 f77f48a879c7b1f1"));
  test_hash(&nettle_sha512,
	    SDATA("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef"
		  "ghijklmnopqrstuvwxyz0123456789"),
	    SHEX("1e07be23c26a86ea 37ea810c8ec78093"
		 "52515a970e9253c2 6f536cfc7a9996c4"
		 "5c8370583e0a78fa 4a90041d71a4ceab"
		 "7423f19c71b9d5a3 e01249f0bebd5894"));
  test_hash(&nettle_sha512,
	    SDATA("12345678901234567890123456789012"
		  "34567890123456789012345678901234"
		  "5678901234567890"),
	    SHEX("72ec1ef1124a45b0 47e8b7c75a932195"
		 "135bb61de24ec0d1 914042246e0aec3a"
		 "2354e093d76f3048 b456764346900cb1"
		 "30d2a4fd5dd16abb 5e30bcb850dee843"));
}

/* For first test case.
-1: 6a09e667f3bcc908 bb67ae8584caa73b 3c6ef372fe94f82b a54ff53a5f1d36f1  510e527fade682d1 9b05688c2b3e6c1f 1f83d9abfb41bd6b 5be0cd19137e2179
 0: 6a09e667f3bcc908 bb67ae8584caa73b 3c6ef372fe94f82b 58cb02347ab51f91  510e527fade682d1 9b05688c2b3e6c1f 1f83d9abfb41bd6b f6afceb8bcfcddf5
 1: 6a09e667f3bcc908 bb67ae8584caa73b c3d4ebfd48650ffa 58cb02347ab51f91  510e527fade682d1 9b05688c2b3e6c1f 1320f8c9fb872cc0 f6afceb8bcfcddf5
 6:  b47b4bb1928990e c4875b0c7abc076b af573b02403e89cd b680953951604860  5a83cb3e80050e82 5a6c781f54dcc00c 96f60209b6dc35ba 745aca4a342ed2e2
 7: 8093d195e0054fa3 c4875b0c7abc076b af573b02403e89cd b680953951604860  86f67263a0f0ec0a 5a6c781f54dcc00c 96f60209b6dc35ba 745aca4a342ed2e2
 8: 8093d195e0054fa3 c4875b0c7abc076b af573b02403e89cd d0403c398fc40002  86f67263a0f0ec0a 5a6c781f54dcc00c 96f60209b6dc35ba f1eca5544cb89225
 9: 8093d195e0054fa3 c4875b0c7abc076b    91f460be46c52 d0403c398fc40002  86f67263a0f0ec0a 5a6c781f54dcc00c 81782d4a5db48f03 f1eca5544cb89225
14: 475975b91a7a462c fa967eed85a08028 44249631255d2ca0 5e41214388186c14  db0a9963f80c2eaa 874bfe5f6aae9f2f 860acf9effba6f61 cdf3bff2883fc9d9
15:  ae07c86b1181c75 fa967eed85a08028 44249631255d2ca0 5e41214388186c14  a77b7c035dd4c161 874bfe5f6aae9f2f 860acf9effba6f61 cdf3bff2883fc9d9
16:  ae07c86b1181c75 fa967eed85a08028 44249631255d2ca0 2deecc6b39d64d78  a77b7c035dd4c161 874bfe5f6aae9f2f 860acf9effba6f61 caf81a425d800537
17:  ae07c86b1181c75 fa967eed85a08028 f47e8353f8047455 2deecc6b39d64d78  a77b7c035dd4c161 874bfe5f6aae9f2f 4725be249ad19e6b caf81a425d800537
18:  ae07c86b1181c75 29695fd88d81dbd0 f47e8353f8047455 2deecc6b39d64d78  a77b7c035dd4c161 3c4b4104168e3edb 4725be249ad19e6b caf81a425d800537
30:  9068a4e255a0dac 4c4fbbb75f1873a6 74bf40f869094c63 e62349090f47d30a  eab4a9e5771b8d09 73e025d91b9efea3 f0aec2fe1437f085  fcdf99710f21584
31: ff4d3f1f0d46a736 4c4fbbb75f1873a6 74bf40f869094c63 e62349090f47d30a  3cd388e119e8162e 73e025d91b9efea3 f0aec2fe1437f085  fcdf99710f21584
32: ff4d3f1f0d46a736 4c4fbbb75f1873a6 74bf40f869094c63 e1034573654a106f  3cd388e119e8162e 73e025d91b9efea3 f0aec2fe1437f085 a0509015ca08c8d4
33: ff4d3f1f0d46a736 4c4fbbb75f1873a6 efabbd8bf47c041a e1034573654a106f  3cd388e119e8162e 73e025d91b9efea3 60d4e6995ed91fe6 a0509015ca08c8d4
34: ff4d3f1f0d46a736  fbae670fa780fd3 efabbd8bf47c041a e1034573654a106f  3cd388e119e8162e 2c59ec7743632621 60d4e6995ed91fe6 a0509015ca08c8d4
46: cc5100997f5710f2 f61e672694de2d67  21fbadbabab5ac6 c47c9d5c7ea8a234  35d7e7f41defcbd5 c6bc35740d8daa9a e95c2a57572d64d9 858d832ae0e8911c
47: 6b69fc1bb482feac f61e672694de2d67  21fbadbabab5ac6 c47c9d5c7ea8a234  35264334c03ac8ad c6bc35740d8daa9a e95c2a57572d64d9 858d832ae0e8911c
48: 6b69fc1bb482feac f61e672694de2d67  21fbadbabab5ac6 271580ed6c3e5650  35264334c03ac8ad c6bc35740d8daa9a e95c2a57572d64d9 571f323d96b3a047
49: 6b69fc1bb482feac f61e672694de2d67 dfe091dab182e645 271580ed6c3e5650  35264334c03ac8ad c6bc35740d8daa9a ca9bd862c5050918 571f323d96b3a047
50: 6b69fc1bb482feac  7a0d8ef821c5e1a dfe091dab182e645 271580ed6c3e5650  35264334c03ac8ad 813a43dd2c502043 ca9bd862c5050918 571f323d96b3a047
62: 4797cde4ed370692 a81dedbb9f19e643 cfcd928c5424e2b6 3857dfd2fc37d3ba  2c074484ef1eac8c 84058865d60a05fa  9aee5bda1644de5 a6af4e9c9f807e51
63: ab44e86276478d85 a81dedbb9f19e643 cfcd928c5424e2b6 3857dfd2fc37d3ba  cd881ee59ca6bc53 84058865d60a05fa  9aee5bda1644de5 a6af4e9c9f807e51
64: ab44e86276478d85 a81dedbb9f19e643 cfcd928c5424e2b6 aa84b086688a5c45  cd881ee59ca6bc53 84058865d60a05fa  9aee5bda1644de5 5a806d7e9821a501
65: ab44e86276478d85 a81dedbb9f19e643 3b5fed0d6a1f96e1 aa84b086688a5c45  cd881ee59ca6bc53 84058865d60a05fa eeb9c21bb0102598 5a806d7e9821a501
66: ab44e86276478d85 29fab5a7bff53366 3b5fed0d6a1f96e1 aa84b086688a5c45  cd881ee59ca6bc53 46c4210ab2cc155d eeb9c21bb0102598 5a806d7e9821a501
78: 995019a6ff3ba3de 10d9c4c4295599f6 d67806db8b148677 654ef9abec389ca9  c8960e6be864b916 9bb4d39778c07f9e 25c96a7768fb2aa3 ceb9fc3691ce8326
79: 73a54f399fa4b1b2 10d9c4c4295599f6 d67806db8b148677 654ef9abec389ca9  d08446aa79693ed7 9bb4d39778c07f9e 25c96a7768fb2aa3 ceb9fc3691ce8326
99: ddaf35a193617aba cc417349ae204131 12e6fa4e89a97ea2  a9eeee64b55d39a  2192992a274fc1a8 36ba3c23a3feebbd 454d4423643ce80e 2a9ac94fa54ca49f
*/
