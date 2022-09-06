# JSON

## SSB

+ 1.1：

  ```
  Query: ssb/original/1.1.sql
  Plan result:
  {
    "outputFields": ["REVENUE"],
    "plan": {
      "inputs": [{
        "inputs": [{
          "condition": {
            "operands": [
              {"inputRef": "d_datekey"},
              {"inputRef": "lo_orderdate"}
            ],
            "op": "EQUALS"
          },
          "inputs": [
            {
              "condition": {
                "operands": [
                  {"inputRef": "d_year"},
                  {"literal": {
                    "type": "BIGINT",
                    "value": 1992
                  }}
                ],
                "op": "EQUALS"
              },
              "inputs": [{
                "inputs": [{
                  "schema": "ssb-sf1-sortlineorder/csv/",
                  "inputs": [],
                  "operator": "EnumerableTableScan",
                  "table": "date"
                }],
                "fields": [
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  }
                ],
                "operator": "EnumerableProject"
              }],
              "operator": "EnumerableFilter"
            },
            {
              "condition": {
                "operands": [
                  {
                    "operands": [
                      {
                        "operands": [
                          {"inputRef": "lo_discount"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 1
                          }}
                        ],
                        "op": "GREATER_THAN_OR_EQUAL"
                      },
                      {
                        "operands": [
                          {"inputRef": "lo_discount"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 3
                          }}
                        ],
                        "op": "LESS_THAN_OR_EQUAL"
                      }
                    ],
                    "op": "AND"
                  },
                  {
                    "operands": [
                      {"inputRef": "lo_quantity"},
                      {"literal": {
                        "type": "INTEGER",
                        "value": 25
                      }}
                    ],
                    "op": "LESS_THAN"
                  }
                ],
                "op": "AND"
              },
              "inputs": [{
                "inputs": [{
                  "schema": "ssb-sf1-sortlineorder/csv/",
                  "inputs": [],
                  "operator": "EnumerableTableScan",
                  "table": "lineorder"
                }],
                "fields": [
                  {
                    "name": "lo_quantity",
                    "expr": {"inputRef": "lo_quantity"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "lo_extendedprice",
                    "expr": {"inputRef": "lo_extendedprice"}
                  },
                  {
                    "name": "lo_discount",
                    "expr": {"inputRef": "lo_discount"}
                  }
                ],
                "operator": "EnumerableProject"
              }],
              "operator": "EnumerableFilter"
            }
          ],
          "joinType": "INNER",
          "operator": "EnumerableHashJoin"
        }],
        "fields": [{
          "name": "$f0",
          "expr": {
            "operands": [
              {"inputRef": "lo_extendedprice"},
              {"inputRef": "lo_discount"}
            ],
            "op": "TIMES"
          }
        }],
        "operator": "EnumerableProject"
      }],
      "groupFields": [],
      "aggregations": [{
        "aggOutputField": "REVENUE",
        "aggInputField": "$f0",
        "aggFunction": "SUM"
      }],
      "operator": "EnumerableAggregate"
    }
  }
  ```

+ 1.2：

  ```
  Query: ssb/original/1.2.sql
  Plan result:
  {
    "outputFields": ["REVENUE"],
    "plan": {
      "inputs": [{
        "inputs": [{
          "condition": {
            "operands": [
              {"inputRef": "d_datekey"},
              {"inputRef": "lo_orderdate"}
            ],
            "op": "EQUALS"
          },
          "inputs": [
            {
              "condition": {
                "operands": [
                  {"inputRef": "d_yearmonthnum"},
                  {"literal": {
                    "type": "BIGINT",
                    "value": 199201
                  }}
                ],
                "op": "EQUALS"
              },
              "inputs": [{
                "inputs": [{
                  "schema": "ssb-sf1-sortlineorder/csv/",
                  "inputs": [],
                  "operator": "EnumerableTableScan",
                  "table": "date"
                }],
                "fields": [
                  {
                    "name": "d_yearmonthnum",
                    "expr": {"inputRef": "d_yearmonthnum"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  }
                ],
                "operator": "EnumerableProject"
              }],
              "operator": "EnumerableFilter"
            },
            {
              "condition": {
                "operands": [
                  {
                    "operands": [
                      {
                        "operands": [
                          {"inputRef": "lo_discount"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 4
                          }}
                        ],
                        "op": "GREATER_THAN_OR_EQUAL"
                      },
                      {
                        "operands": [
                          {"inputRef": "lo_discount"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 6
                          }}
                        ],
                        "op": "LESS_THAN_OR_EQUAL"
                      }
                    ],
                    "op": "AND"
                  },
                  {
                    "operands": [
                      {
                        "operands": [
                          {"inputRef": "lo_quantity"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 26
                          }}
                        ],
                        "op": "GREATER_THAN_OR_EQUAL"
                      },
                      {
                        "operands": [
                          {"inputRef": "lo_quantity"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 35
                          }}
                        ],
                        "op": "LESS_THAN_OR_EQUAL"
                      }
                    ],
                    "op": "AND"
                  }
                ],
                "op": "AND"
              },
              "inputs": [{
                "inputs": [{
                  "schema": "ssb-sf1-sortlineorder/csv/",
                  "inputs": [],
                  "operator": "EnumerableTableScan",
                  "table": "lineorder"
                }],
                "fields": [
                  {
                    "name": "lo_quantity",
                    "expr": {"inputRef": "lo_quantity"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "lo_extendedprice",
                    "expr": {"inputRef": "lo_extendedprice"}
                  },
                  {
                    "name": "lo_discount",
                    "expr": {"inputRef": "lo_discount"}
                  }
                ],
                "operator": "EnumerableProject"
              }],
              "operator": "EnumerableFilter"
            }
          ],
          "joinType": "INNER",
          "operator": "EnumerableHashJoin"
        }],
        "fields": [{
          "name": "$f0",
          "expr": {
            "operands": [
              {"inputRef": "lo_extendedprice"},
              {"inputRef": "lo_discount"}
            ],
            "op": "TIMES"
          }
        }],
        "operator": "EnumerableProject"
      }],
      "groupFields": [],
      "aggregations": [{
        "aggOutputField": "REVENUE",
        "aggInputField": "$f0",
        "aggFunction": "SUM"
      }],
      "operator": "EnumerableAggregate"
    }
  }
  ```

+ 1.3：

  ```
  Query: ssb/original/1.3.sql
  Plan result:
  {
    "outputFields": ["REVENUE"],
    "plan": {
      "inputs": [{
        "inputs": [{
          "condition": {
            "operands": [
              {"inputRef": "d_datekey"},
              {"inputRef": "lo_orderdate"}
            ],
            "op": "EQUALS"
          },
          "inputs": [
            {
              "condition": {
                "operands": [
                  {
                    "operands": [
                      {"inputRef": "d_weeknuminyear"},
                      {"literal": {
                        "type": "BIGINT",
                        "value": 3
                      }}
                    ],
                    "op": "EQUALS"
                  },
                  {
                    "operands": [
                      {"inputRef": "d_year"},
                      {"literal": {
                        "type": "BIGINT",
                        "value": 1992
                      }}
                    ],
                    "op": "EQUALS"
                  }
                ],
                "op": "AND"
              },
              "inputs": [{
                "inputs": [{
                  "schema": "ssb-sf1-sortlineorder/csv/",
                  "inputs": [],
                  "operator": "EnumerableTableScan",
                  "table": "date"
                }],
                "fields": [
                  {
                    "name": "d_weeknuminyear",
                    "expr": {"inputRef": "d_weeknuminyear"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  }
                ],
                "operator": "EnumerableProject"
              }],
              "operator": "EnumerableFilter"
            },
            {
              "condition": {
                "operands": [
                  {
                    "operands": [
                      {
                        "operands": [
                          {"inputRef": "lo_discount"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 5
                          }}
                        ],
                        "op": "GREATER_THAN_OR_EQUAL"
                      },
                      {
                        "operands": [
                          {"inputRef": "lo_discount"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 7
                          }}
                        ],
                        "op": "LESS_THAN_OR_EQUAL"
                      }
                    ],
                    "op": "AND"
                  },
                  {
                    "operands": [
                      {
                        "operands": [
                          {"inputRef": "lo_quantity"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 26
                          }}
                        ],
                        "op": "GREATER_THAN_OR_EQUAL"
                      },
                      {
                        "operands": [
                          {"inputRef": "lo_quantity"},
                          {"literal": {
                            "type": "INTEGER",
                            "value": 35
                          }}
                        ],
                        "op": "LESS_THAN_OR_EQUAL"
                      }
                    ],
                    "op": "AND"
                  }
                ],
                "op": "AND"
              },
              "inputs": [{
                "inputs": [{
                  "schema": "ssb-sf1-sortlineorder/csv/",
                  "inputs": [],
                  "operator": "EnumerableTableScan",
                  "table": "lineorder"
                }],
                "fields": [
                  {
                    "name": "lo_quantity",
                    "expr": {"inputRef": "lo_quantity"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "lo_extendedprice",
                    "expr": {"inputRef": "lo_extendedprice"}
                  },
                  {
                    "name": "lo_discount",
                    "expr": {"inputRef": "lo_discount"}
                  }
                ],
                "operator": "EnumerableProject"
              }],
              "operator": "EnumerableFilter"
            }
          ],
          "joinType": "INNER",
          "operator": "EnumerableHashJoin"
        }],
        "fields": [{
          "name": "$f0",
          "expr": {
            "operands": [
              {"inputRef": "lo_extendedprice"},
              {"inputRef": "lo_discount"}
            ],
            "op": "TIMES"
          }
        }],
        "operator": "EnumerableProject"
      }],
      "groupFields": [],
      "aggregations": [{
        "aggOutputField": "REVENUE",
        "aggInputField": "$f0",
        "aggFunction": "SUM"
      }],
      "operator": "EnumerableAggregate"
    }
  }
  ```

+ 2.1：

  ```
  Query: ssb/original/2.1.sql
  Plan result:
  {
    "outputFields": [
      "EXPR$0",
      "D_YEAR",
      "P_BRAND1"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "inputs": [{
              "condition": {
                "operands": [
                  {"inputRef": "p_partkey"},
                  {"inputRef": "lo_partkey"}
                ],
                "op": "EQUALS"
              },
              "inputs": [
                {
                  "condition": {
                    "operands": [
                      {"inputRef": "p_category"},
                      {"literal": {
                        "type": "VARCHAR",
                        "value": "MFGR#12"
                      }}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [{
                    "inputs": [{
                      "schema": "ssb-sf1-sortlineorder/csv/",
                      "inputs": [],
                      "operator": "EnumerableTableScan",
                      "table": "part"
                    }],
                    "fields": [
                      {
                        "name": "p_partkey",
                        "expr": {"inputRef": "p_partkey"}
                      },
                      {
                        "name": "p_category",
                        "expr": {"inputRef": "p_category"}
                      },
                      {
                        "name": "p_brand1",
                        "expr": {"inputRef": "p_brand1"}
                      }
                    ],
                    "operator": "EnumerableProject"
                  }],
                  "operator": "EnumerableFilter"
                },
                {
                  "inputs": [{
                    "condition": {
                      "operands": [
                        {"inputRef": "d_datekey"},
                        {"inputRef": "lo_orderdate"}
                      ],
                      "op": "EQUALS"
                    },
                    "inputs": [
                      {
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "date"
                        }],
                        "fields": [
                          {
                            "name": "d_datekey",
                            "expr": {"inputRef": "d_datekey"}
                          },
                          {
                            "name": "d_year",
                            "expr": {"inputRef": "d_year"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      },
                      {
                        "inputs": [{
                          "condition": {
                            "operands": [
                              {"inputRef": "s_suppkey"},
                              {"inputRef": "lo_suppkey"}
                            ],
                            "op": "EQUALS"
                          },
                          "inputs": [
                            {
                              "condition": {
                                "operands": [
                                  {"inputRef": "s_region"},
                                  {"literal": {
                                    "type": "VARCHAR",
                                    "value": "AMERICA"
                                  }}
                                ],
                                "op": "EQUALS"
                              },
                              "inputs": [{
                                "inputs": [{
                                  "schema": "ssb-sf1-sortlineorder/csv/",
                                  "inputs": [],
                                  "operator": "EnumerableTableScan",
                                  "table": "supplier"
                                }],
                                "fields": [
                                  {
                                    "name": "s_suppkey",
                                    "expr": {"inputRef": "s_suppkey"}
                                  },
                                  {
                                    "name": "s_region",
                                    "expr": {"inputRef": "s_region"}
                                  }
                                ],
                                "operator": "EnumerableProject"
                              }],
                              "operator": "EnumerableFilter"
                            },
                            {
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "lineorder"
                              }],
                              "fields": [
                                {
                                  "name": "lo_partkey",
                                  "expr": {"inputRef": "lo_partkey"}
                                },
                                {
                                  "name": "lo_revenue",
                                  "expr": {"inputRef": "lo_revenue"}
                                },
                                {
                                  "name": "lo_suppkey",
                                  "expr": {"inputRef": "lo_suppkey"}
                                },
                                {
                                  "name": "lo_orderdate",
                                  "expr": {"inputRef": "lo_orderdate"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }
                          ],
                          "joinType": "INNER",
                          "operator": "EnumerableHashJoin"
                        }],
                        "fields": [
                          {
                            "name": "lo_partkey",
                            "expr": {"inputRef": "lo_partkey"}
                          },
                          {
                            "name": "lo_revenue",
                            "expr": {"inputRef": "lo_revenue"}
                          },
                          {
                            "name": "lo_suppkey",
                            "expr": {"inputRef": "lo_suppkey"}
                          },
                          {
                            "name": "lo_orderdate",
                            "expr": {"inputRef": "lo_orderdate"}
                          },
                          {
                            "name": "s_suppkey",
                            "expr": {"inputRef": "s_suppkey"}
                          },
                          {
                            "name": "s_region",
                            "expr": {"inputRef": "s_region"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }
                    ],
                    "joinType": "INNER",
                    "operator": "EnumerableHashJoin"
                  }],
                  "fields": [
                    {
                      "name": "lo_partkey",
                      "expr": {"inputRef": "lo_partkey"}
                    },
                    {
                      "name": "lo_revenue",
                      "expr": {"inputRef": "lo_revenue"}
                    },
                    {
                      "name": "lo_suppkey",
                      "expr": {"inputRef": "lo_suppkey"}
                    },
                    {
                      "name": "lo_orderdate",
                      "expr": {"inputRef": "lo_orderdate"}
                    },
                    {
                      "name": "s_suppkey",
                      "expr": {"inputRef": "s_suppkey"}
                    },
                    {
                      "name": "s_region",
                      "expr": {"inputRef": "s_region"}
                    },
                    {
                      "name": "d_datekey",
                      "expr": {"inputRef": "d_datekey"}
                    },
                    {
                      "name": "d_year",
                      "expr": {"inputRef": "d_year"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }
              ],
              "joinType": "INNER",
              "operator": "EnumerableHashJoin"
            }],
            "fields": [
              {
                "name": "d_year",
                "expr": {"inputRef": "d_year"}
              },
              {
                "name": "p_brand1",
                "expr": {"inputRef": "p_brand1"}
              },
              {
                "name": "lo_revenue",
                "expr": {"inputRef": "lo_revenue"}
              }
            ],
            "operator": "EnumerableProject"
          }],
          "groupFields": [
            "d_year",
            "p_brand1"
          ],
          "aggregations": [{
            "aggOutputField": "EXPR$0",
            "aggInputField": "lo_revenue",
            "aggFunction": "SUM"
          }],
          "operator": "EnumerableAggregate"
        }],
        "fields": [
          {
            "name": "EXPR$0",
            "expr": {"inputRef": "EXPR$0"}
          },
          {
            "name": "D_YEAR",
            "expr": {"inputRef": "d_year"}
          },
          {
            "name": "P_BRAND1",
            "expr": {"inputRef": "p_brand1"}
          }
        ],
        "operator": "EnumerableProject"
      }],
      "sortFields": [
        {
          "field": "D_YEAR",
          "direction": "ASCENDING"
        },
        {
          "field": "P_BRAND1",
          "direction": "ASCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 2.2：

  ```
  Query: ssb/original/2.2.sql
  Plan result:
  {
    "outputFields": [
      "EXPR$0",
      "D_YEAR",
      "P_BRAND1"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "inputs": [{
              "condition": {
                "operands": [
                  {"inputRef": "p_partkey"},
                  {"inputRef": "lo_partkey"}
                ],
                "op": "EQUALS"
              },
              "inputs": [
                {
                  "condition": {
                    "operands": [
                      {
                        "operands": [
                          {"inputRef": "p_brand1"},
                          {"literal": {
                            "type": "CHAR",
                            "value": "MFGR#2221"
                          }}
                        ],
                        "op": "GREATER_THAN_OR_EQUAL"
                      },
                      {
                        "operands": [
                          {"inputRef": "p_brand1"},
                          {"literal": {
                            "type": "CHAR",
                            "value": "MFGR#2228"
                          }}
                        ],
                        "op": "LESS_THAN_OR_EQUAL"
                      }
                    ],
                    "op": "AND"
                  },
                  "inputs": [{
                    "inputs": [{
                      "schema": "ssb-sf1-sortlineorder/csv/",
                      "inputs": [],
                      "operator": "EnumerableTableScan",
                      "table": "part"
                    }],
                    "fields": [
                      {
                        "name": "p_partkey",
                        "expr": {"inputRef": "p_partkey"}
                      },
                      {
                        "name": "p_brand1",
                        "expr": {"inputRef": "p_brand1"}
                      }
                    ],
                    "operator": "EnumerableProject"
                  }],
                  "operator": "EnumerableFilter"
                },
                {
                  "inputs": [{
                    "condition": {
                      "operands": [
                        {"inputRef": "d_datekey"},
                        {"inputRef": "lo_orderdate"}
                      ],
                      "op": "EQUALS"
                    },
                    "inputs": [
                      {
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "date"
                        }],
                        "fields": [
                          {
                            "name": "d_datekey",
                            "expr": {"inputRef": "d_datekey"}
                          },
                          {
                            "name": "d_year",
                            "expr": {"inputRef": "d_year"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      },
                      {
                        "inputs": [{
                          "condition": {
                            "operands": [
                              {"inputRef": "s_suppkey"},
                              {"inputRef": "lo_suppkey"}
                            ],
                            "op": "EQUALS"
                          },
                          "inputs": [
                            {
                              "condition": {
                                "operands": [
                                  {"inputRef": "s_region"},
                                  {"literal": {
                                    "type": "VARCHAR",
                                    "value": "ASIA"
                                  }}
                                ],
                                "op": "EQUALS"
                              },
                              "inputs": [{
                                "inputs": [{
                                  "schema": "ssb-sf1-sortlineorder/csv/",
                                  "inputs": [],
                                  "operator": "EnumerableTableScan",
                                  "table": "supplier"
                                }],
                                "fields": [
                                  {
                                    "name": "s_suppkey",
                                    "expr": {"inputRef": "s_suppkey"}
                                  },
                                  {
                                    "name": "s_region",
                                    "expr": {"inputRef": "s_region"}
                                  }
                                ],
                                "operator": "EnumerableProject"
                              }],
                              "operator": "EnumerableFilter"
                            },
                            {
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "lineorder"
                              }],
                              "fields": [
                                {
                                  "name": "lo_partkey",
                                  "expr": {"inputRef": "lo_partkey"}
                                },
                                {
                                  "name": "lo_revenue",
                                  "expr": {"inputRef": "lo_revenue"}
                                },
                                {
                                  "name": "lo_suppkey",
                                  "expr": {"inputRef": "lo_suppkey"}
                                },
                                {
                                  "name": "lo_orderdate",
                                  "expr": {"inputRef": "lo_orderdate"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }
                          ],
                          "joinType": "INNER",
                          "operator": "EnumerableHashJoin"
                        }],
                        "fields": [
                          {
                            "name": "lo_partkey",
                            "expr": {"inputRef": "lo_partkey"}
                          },
                          {
                            "name": "lo_revenue",
                            "expr": {"inputRef": "lo_revenue"}
                          },
                          {
                            "name": "lo_suppkey",
                            "expr": {"inputRef": "lo_suppkey"}
                          },
                          {
                            "name": "lo_orderdate",
                            "expr": {"inputRef": "lo_orderdate"}
                          },
                          {
                            "name": "s_suppkey",
                            "expr": {"inputRef": "s_suppkey"}
                          },
                          {
                            "name": "s_region",
                            "expr": {"inputRef": "s_region"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }
                    ],
                    "joinType": "INNER",
                    "operator": "EnumerableHashJoin"
                  }],
                  "fields": [
                    {
                      "name": "lo_partkey",
                      "expr": {"inputRef": "lo_partkey"}
                    },
                    {
                      "name": "lo_revenue",
                      "expr": {"inputRef": "lo_revenue"}
                    },
                    {
                      "name": "lo_suppkey",
                      "expr": {"inputRef": "lo_suppkey"}
                    },
                    {
                      "name": "lo_orderdate",
                      "expr": {"inputRef": "lo_orderdate"}
                    },
                    {
                      "name": "s_suppkey",
                      "expr": {"inputRef": "s_suppkey"}
                    },
                    {
                      "name": "s_region",
                      "expr": {"inputRef": "s_region"}
                    },
                    {
                      "name": "d_datekey",
                      "expr": {"inputRef": "d_datekey"}
                    },
                    {
                      "name": "d_year",
                      "expr": {"inputRef": "d_year"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }
              ],
              "joinType": "INNER",
              "operator": "EnumerableHashJoin"
            }],
            "fields": [
              {
                "name": "d_year",
                "expr": {"inputRef": "d_year"}
              },
              {
                "name": "p_brand1",
                "expr": {"inputRef": "p_brand1"}
              },
              {
                "name": "lo_revenue",
                "expr": {"inputRef": "lo_revenue"}
              }
            ],
            "operator": "EnumerableProject"
          }],
          "groupFields": [
            "d_year",
            "p_brand1"
          ],
          "aggregations": [{
            "aggOutputField": "EXPR$0",
            "aggInputField": "lo_revenue",
            "aggFunction": "SUM"
          }],
          "operator": "EnumerableAggregate"
        }],
        "fields": [
          {
            "name": "EXPR$0",
            "expr": {"inputRef": "EXPR$0"}
          },
          {
            "name": "D_YEAR",
            "expr": {"inputRef": "d_year"}
          },
          {
            "name": "P_BRAND1",
            "expr": {"inputRef": "p_brand1"}
          }
        ],
        "operator": "EnumerableProject"
      }],
      "sortFields": [
        {
          "field": "D_YEAR",
          "direction": "ASCENDING"
        },
        {
          "field": "P_BRAND1",
          "direction": "ASCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 2.3：

  ```
  Query: ssb/original/2.3.sql
  Plan result:
  {
    "outputFields": [
      "EXPR$0",
      "D_YEAR",
      "P_BRAND1"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "inputs": [{
              "condition": {
                "operands": [
                  {"inputRef": "p_partkey"},
                  {"inputRef": "lo_partkey"}
                ],
                "op": "EQUALS"
              },
              "inputs": [
                {
                  "condition": {
                    "operands": [
                      {"inputRef": "p_brand1"},
                      {"literal": {
                        "type": "VARCHAR",
                        "value": "MFGR#2221"
                      }}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [{
                    "inputs": [{
                      "schema": "ssb-sf1-sortlineorder/csv/",
                      "inputs": [],
                      "operator": "EnumerableTableScan",
                      "table": "part"
                    }],
                    "fields": [
                      {
                        "name": "p_partkey",
                        "expr": {"inputRef": "p_partkey"}
                      },
                      {
                        "name": "p_brand1",
                        "expr": {"inputRef": "p_brand1"}
                      }
                    ],
                    "operator": "EnumerableProject"
                  }],
                  "operator": "EnumerableFilter"
                },
                {
                  "inputs": [{
                    "condition": {
                      "operands": [
                        {"inputRef": "d_datekey"},
                        {"inputRef": "lo_orderdate"}
                      ],
                      "op": "EQUALS"
                    },
                    "inputs": [
                      {
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "date"
                        }],
                        "fields": [
                          {
                            "name": "d_datekey",
                            "expr": {"inputRef": "d_datekey"}
                          },
                          {
                            "name": "d_year",
                            "expr": {"inputRef": "d_year"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      },
                      {
                        "inputs": [{
                          "condition": {
                            "operands": [
                              {"inputRef": "s_suppkey"},
                              {"inputRef": "lo_suppkey"}
                            ],
                            "op": "EQUALS"
                          },
                          "inputs": [
                            {
                              "condition": {
                                "operands": [
                                  {"inputRef": "s_region"},
                                  {"literal": {
                                    "type": "VARCHAR",
                                    "value": "EUROPE"
                                  }}
                                ],
                                "op": "EQUALS"
                              },
                              "inputs": [{
                                "inputs": [{
                                  "schema": "ssb-sf1-sortlineorder/csv/",
                                  "inputs": [],
                                  "operator": "EnumerableTableScan",
                                  "table": "supplier"
                                }],
                                "fields": [
                                  {
                                    "name": "s_suppkey",
                                    "expr": {"inputRef": "s_suppkey"}
                                  },
                                  {
                                    "name": "s_region",
                                    "expr": {"inputRef": "s_region"}
                                  }
                                ],
                                "operator": "EnumerableProject"
                              }],
                              "operator": "EnumerableFilter"
                            },
                            {
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "lineorder"
                              }],
                              "fields": [
                                {
                                  "name": "lo_partkey",
                                  "expr": {"inputRef": "lo_partkey"}
                                },
                                {
                                  "name": "lo_revenue",
                                  "expr": {"inputRef": "lo_revenue"}
                                },
                                {
                                  "name": "lo_suppkey",
                                  "expr": {"inputRef": "lo_suppkey"}
                                },
                                {
                                  "name": "lo_orderdate",
                                  "expr": {"inputRef": "lo_orderdate"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }
                          ],
                          "joinType": "INNER",
                          "operator": "EnumerableHashJoin"
                        }],
                        "fields": [
                          {
                            "name": "lo_partkey",
                            "expr": {"inputRef": "lo_partkey"}
                          },
                          {
                            "name": "lo_revenue",
                            "expr": {"inputRef": "lo_revenue"}
                          },
                          {
                            "name": "lo_suppkey",
                            "expr": {"inputRef": "lo_suppkey"}
                          },
                          {
                            "name": "lo_orderdate",
                            "expr": {"inputRef": "lo_orderdate"}
                          },
                          {
                            "name": "s_suppkey",
                            "expr": {"inputRef": "s_suppkey"}
                          },
                          {
                            "name": "s_region",
                            "expr": {"inputRef": "s_region"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }
                    ],
                    "joinType": "INNER",
                    "operator": "EnumerableHashJoin"
                  }],
                  "fields": [
                    {
                      "name": "lo_partkey",
                      "expr": {"inputRef": "lo_partkey"}
                    },
                    {
                      "name": "lo_revenue",
                      "expr": {"inputRef": "lo_revenue"}
                    },
                    {
                      "name": "lo_suppkey",
                      "expr": {"inputRef": "lo_suppkey"}
                    },
                    {
                      "name": "lo_orderdate",
                      "expr": {"inputRef": "lo_orderdate"}
                    },
                    {
                      "name": "s_suppkey",
                      "expr": {"inputRef": "s_suppkey"}
                    },
                    {
                      "name": "s_region",
                      "expr": {"inputRef": "s_region"}
                    },
                    {
                      "name": "d_datekey",
                      "expr": {"inputRef": "d_datekey"}
                    },
                    {
                      "name": "d_year",
                      "expr": {"inputRef": "d_year"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }
              ],
              "joinType": "INNER",
              "operator": "EnumerableHashJoin"
            }],
            "fields": [
              {
                "name": "d_year",
                "expr": {"inputRef": "d_year"}
              },
              {
                "name": "p_brand1",
                "expr": {"inputRef": "p_brand1"}
              },
              {
                "name": "lo_revenue",
                "expr": {"inputRef": "lo_revenue"}
              }
            ],
            "operator": "EnumerableProject"
          }],
          "groupFields": [
            "d_year",
            "p_brand1"
          ],
          "aggregations": [{
            "aggOutputField": "EXPR$0",
            "aggInputField": "lo_revenue",
            "aggFunction": "SUM"
          }],
          "operator": "EnumerableAggregate"
        }],
        "fields": [
          {
            "name": "EXPR$0",
            "expr": {"inputRef": "EXPR$0"}
          },
          {
            "name": "D_YEAR",
            "expr": {"inputRef": "d_year"}
          },
          {
            "name": "P_BRAND1",
            "expr": {"inputRef": "p_brand1"}
          }
        ],
        "operator": "EnumerableProject"
      }],
      "sortFields": [
        {
          "field": "D_YEAR",
          "direction": "ASCENDING"
        },
        {
          "field": "P_BRAND1",
          "direction": "ASCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 3.1：

  ```
  Query: ssb/original/3.1.sql
  Plan result:
  {
    "outputFields": [
      "c_nation",
      "s_nation",
      "d_year",
      "REVENUE"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "condition": {
              "operands": [
                {"inputRef": "c_custkey"},
                {"inputRef": "lo_custkey"}
              ],
              "op": "EQUALS"
            },
            "inputs": [
              {
                "condition": {
                  "operands": [
                    {"inputRef": "c_region"},
                    {"literal": {
                      "type": "VARCHAR",
                      "value": "ASIA"
                    }}
                  ],
                  "op": "EQUALS"
                },
                "inputs": [{
                  "inputs": [{
                    "schema": "ssb-sf1-sortlineorder/csv/",
                    "inputs": [],
                    "operator": "EnumerableTableScan",
                    "table": "customer"
                  }],
                  "fields": [
                    {
                      "name": "c_custkey",
                      "expr": {"inputRef": "c_custkey"}
                    },
                    {
                      "name": "c_nation",
                      "expr": {"inputRef": "c_nation"}
                    },
                    {
                      "name": "c_region",
                      "expr": {"inputRef": "c_region"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }],
                "operator": "EnumerableFilter"
              },
              {
                "inputs": [{
                  "condition": {
                    "operands": [
                      {"inputRef": "d_datekey"},
                      {"inputRef": "lo_orderdate"}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [
                    {
                      "condition": {
                        "operands": [
                          {
                            "operands": [
                              {"inputRef": "d_year"},
                              {"literal": {
                                "type": "INTEGER",
                                "value": 1992
                              }}
                            ],
                            "op": "GREATER_THAN_OR_EQUAL"
                          },
                          {
                            "operands": [
                              {"inputRef": "d_year"},
                              {"literal": {
                                "type": "INTEGER",
                                "value": 1997
                              }}
                            ],
                            "op": "LESS_THAN_OR_EQUAL"
                          }
                        ],
                        "op": "AND"
                      },
                      "inputs": [{
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "date"
                        }],
                        "fields": [
                          {
                            "name": "d_datekey",
                            "expr": {"inputRef": "d_datekey"}
                          },
                          {
                            "name": "d_year",
                            "expr": {"inputRef": "d_year"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }],
                      "operator": "EnumerableFilter"
                    },
                    {
                      "inputs": [{
                        "condition": {
                          "operands": [
                            {"inputRef": "s_suppkey"},
                            {"inputRef": "lo_suppkey"}
                          ],
                          "op": "EQUALS"
                        },
                        "inputs": [
                          {
                            "condition": {
                              "operands": [
                                {"inputRef": "s_region"},
                                {"literal": {
                                  "type": "VARCHAR",
                                  "value": "ASIA"
                                }}
                              ],
                              "op": "EQUALS"
                            },
                            "inputs": [{
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "supplier"
                              }],
                              "fields": [
                                {
                                  "name": "s_nation",
                                  "expr": {"inputRef": "s_nation"}
                                },
                                {
                                  "name": "s_suppkey",
                                  "expr": {"inputRef": "s_suppkey"}
                                },
                                {
                                  "name": "s_region",
                                  "expr": {"inputRef": "s_region"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }],
                            "operator": "EnumerableFilter"
                          },
                          {
                            "inputs": [{
                              "schema": "ssb-sf1-sortlineorder/csv/",
                              "inputs": [],
                              "operator": "EnumerableTableScan",
                              "table": "lineorder"
                            }],
                            "fields": [
                              {
                                "name": "lo_custkey",
                                "expr": {"inputRef": "lo_custkey"}
                              },
                              {
                                "name": "lo_revenue",
                                "expr": {"inputRef": "lo_revenue"}
                              },
                              {
                                "name": "lo_suppkey",
                                "expr": {"inputRef": "lo_suppkey"}
                              },
                              {
                                "name": "lo_orderdate",
                                "expr": {"inputRef": "lo_orderdate"}
                              }
                            ],
                            "operator": "EnumerableProject"
                          }
                        ],
                        "joinType": "INNER",
                        "operator": "EnumerableHashJoin"
                      }],
                      "fields": [
                        {
                          "name": "lo_custkey",
                          "expr": {"inputRef": "lo_custkey"}
                        },
                        {
                          "name": "lo_revenue",
                          "expr": {"inputRef": "lo_revenue"}
                        },
                        {
                          "name": "lo_suppkey",
                          "expr": {"inputRef": "lo_suppkey"}
                        },
                        {
                          "name": "lo_orderdate",
                          "expr": {"inputRef": "lo_orderdate"}
                        },
                        {
                          "name": "s_nation",
                          "expr": {"inputRef": "s_nation"}
                        },
                        {
                          "name": "s_suppkey",
                          "expr": {"inputRef": "s_suppkey"}
                        },
                        {
                          "name": "s_region",
                          "expr": {"inputRef": "s_region"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    }
                  ],
                  "joinType": "INNER",
                  "operator": "EnumerableHashJoin"
                }],
                "fields": [
                  {
                    "name": "lo_custkey",
                    "expr": {"inputRef": "lo_custkey"}
                  },
                  {
                    "name": "lo_revenue",
                    "expr": {"inputRef": "lo_revenue"}
                  },
                  {
                    "name": "lo_suppkey",
                    "expr": {"inputRef": "lo_suppkey"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "s_nation",
                    "expr": {"inputRef": "s_nation"}
                  },
                  {
                    "name": "s_suppkey",
                    "expr": {"inputRef": "s_suppkey"}
                  },
                  {
                    "name": "s_region",
                    "expr": {"inputRef": "s_region"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  }
                ],
                "operator": "EnumerableProject"
              }
            ],
            "joinType": "INNER",
            "operator": "EnumerableHashJoin"
          }],
          "fields": [
            {
              "name": "c_nation",
              "expr": {"inputRef": "c_nation"}
            },
            {
              "name": "s_nation",
              "expr": {"inputRef": "s_nation"}
            },
            {
              "name": "d_year",
              "expr": {"inputRef": "d_year"}
            },
            {
              "name": "lo_revenue",
              "expr": {"inputRef": "lo_revenue"}
            }
          ],
          "operator": "EnumerableProject"
        }],
        "groupFields": [
          "c_nation",
          "s_nation",
          "d_year"
        ],
        "aggregations": [{
          "aggOutputField": "REVENUE",
          "aggInputField": "lo_revenue",
          "aggFunction": "SUM"
        }],
        "operator": "EnumerableAggregate"
      }],
      "sortFields": [
        {
          "field": "d_year",
          "direction": "ASCENDING"
        },
        {
          "field": "REVENUE",
          "direction": "DESCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 3.2：

  ```
  Query: ssb/original/3.2.sql
  Plan result:
  {
    "outputFields": [
      "c_city",
      "s_city",
      "d_year",
      "REVENUE"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "condition": {
              "operands": [
                {"inputRef": "c_custkey"},
                {"inputRef": "lo_custkey"}
              ],
              "op": "EQUALS"
            },
            "inputs": [
              {
                "condition": {
                  "operands": [
                    {"inputRef": "c_nation"},
                    {"literal": {
                      "type": "VARCHAR",
                      "value": "CHINA"
                    }}
                  ],
                  "op": "EQUALS"
                },
                "inputs": [{
                  "inputs": [{
                    "schema": "ssb-sf1-sortlineorder/csv/",
                    "inputs": [],
                    "operator": "EnumerableTableScan",
                    "table": "customer"
                  }],
                  "fields": [
                    {
                      "name": "c_custkey",
                      "expr": {"inputRef": "c_custkey"}
                    },
                    {
                      "name": "c_nation",
                      "expr": {"inputRef": "c_nation"}
                    },
                    {
                      "name": "c_city",
                      "expr": {"inputRef": "c_city"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }],
                "operator": "EnumerableFilter"
              },
              {
                "inputs": [{
                  "condition": {
                    "operands": [
                      {"inputRef": "d_datekey"},
                      {"inputRef": "lo_orderdate"}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [
                    {
                      "condition": {
                        "operands": [
                          {
                            "operands": [
                              {"inputRef": "d_year"},
                              {"literal": {
                                "type": "INTEGER",
                                "value": 1992
                              }}
                            ],
                            "op": "GREATER_THAN_OR_EQUAL"
                          },
                          {
                            "operands": [
                              {"inputRef": "d_year"},
                              {"literal": {
                                "type": "INTEGER",
                                "value": 1997
                              }}
                            ],
                            "op": "LESS_THAN_OR_EQUAL"
                          }
                        ],
                        "op": "AND"
                      },
                      "inputs": [{
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "date"
                        }],
                        "fields": [
                          {
                            "name": "d_datekey",
                            "expr": {"inputRef": "d_datekey"}
                          },
                          {
                            "name": "d_year",
                            "expr": {"inputRef": "d_year"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }],
                      "operator": "EnumerableFilter"
                    },
                    {
                      "inputs": [{
                        "condition": {
                          "operands": [
                            {"inputRef": "s_suppkey"},
                            {"inputRef": "lo_suppkey"}
                          ],
                          "op": "EQUALS"
                        },
                        "inputs": [
                          {
                            "condition": {
                              "operands": [
                                {"inputRef": "s_nation"},
                                {"literal": {
                                  "type": "VARCHAR",
                                  "value": "UNITED STATES"
                                }}
                              ],
                              "op": "EQUALS"
                            },
                            "inputs": [{
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "supplier"
                              }],
                              "fields": [
                                {
                                  "name": "s_city",
                                  "expr": {"inputRef": "s_city"}
                                },
                                {
                                  "name": "s_nation",
                                  "expr": {"inputRef": "s_nation"}
                                },
                                {
                                  "name": "s_suppkey",
                                  "expr": {"inputRef": "s_suppkey"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }],
                            "operator": "EnumerableFilter"
                          },
                          {
                            "inputs": [{
                              "schema": "ssb-sf1-sortlineorder/csv/",
                              "inputs": [],
                              "operator": "EnumerableTableScan",
                              "table": "lineorder"
                            }],
                            "fields": [
                              {
                                "name": "lo_custkey",
                                "expr": {"inputRef": "lo_custkey"}
                              },
                              {
                                "name": "lo_revenue",
                                "expr": {"inputRef": "lo_revenue"}
                              },
                              {
                                "name": "lo_suppkey",
                                "expr": {"inputRef": "lo_suppkey"}
                              },
                              {
                                "name": "lo_orderdate",
                                "expr": {"inputRef": "lo_orderdate"}
                              }
                            ],
                            "operator": "EnumerableProject"
                          }
                        ],
                        "joinType": "INNER",
                        "operator": "EnumerableHashJoin"
                      }],
                      "fields": [
                        {
                          "name": "lo_custkey",
                          "expr": {"inputRef": "lo_custkey"}
                        },
                        {
                          "name": "lo_revenue",
                          "expr": {"inputRef": "lo_revenue"}
                        },
                        {
                          "name": "lo_suppkey",
                          "expr": {"inputRef": "lo_suppkey"}
                        },
                        {
                          "name": "lo_orderdate",
                          "expr": {"inputRef": "lo_orderdate"}
                        },
                        {
                          "name": "s_city",
                          "expr": {"inputRef": "s_city"}
                        },
                        {
                          "name": "s_nation",
                          "expr": {"inputRef": "s_nation"}
                        },
                        {
                          "name": "s_suppkey",
                          "expr": {"inputRef": "s_suppkey"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    }
                  ],
                  "joinType": "INNER",
                  "operator": "EnumerableHashJoin"
                }],
                "fields": [
                  {
                    "name": "lo_custkey",
                    "expr": {"inputRef": "lo_custkey"}
                  },
                  {
                    "name": "lo_revenue",
                    "expr": {"inputRef": "lo_revenue"}
                  },
                  {
                    "name": "lo_suppkey",
                    "expr": {"inputRef": "lo_suppkey"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "s_city",
                    "expr": {"inputRef": "s_city"}
                  },
                  {
                    "name": "s_nation",
                    "expr": {"inputRef": "s_nation"}
                  },
                  {
                    "name": "s_suppkey",
                    "expr": {"inputRef": "s_suppkey"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  }
                ],
                "operator": "EnumerableProject"
              }
            ],
            "joinType": "INNER",
            "operator": "EnumerableHashJoin"
          }],
          "fields": [
            {
              "name": "c_city",
              "expr": {"inputRef": "c_city"}
            },
            {
              "name": "s_city",
              "expr": {"inputRef": "s_city"}
            },
            {
              "name": "d_year",
              "expr": {"inputRef": "d_year"}
            },
            {
              "name": "lo_revenue",
              "expr": {"inputRef": "lo_revenue"}
            }
          ],
          "operator": "EnumerableProject"
        }],
        "groupFields": [
          "c_city",
          "s_city",
          "d_year"
        ],
        "aggregations": [{
          "aggOutputField": "REVENUE",
          "aggInputField": "lo_revenue",
          "aggFunction": "SUM"
        }],
        "operator": "EnumerableAggregate"
      }],
      "sortFields": [
        {
          "field": "d_year",
          "direction": "ASCENDING"
        },
        {
          "field": "REVENUE",
          "direction": "DESCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 3.3：

  ```
  Query: ssb/original/3.3.sql
  Plan result:
  {
    "outputFields": [
      "c_city",
      "s_city",
      "d_year",
      "REVENUE"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "condition": {
              "operands": [
                {"inputRef": "c_custkey"},
                {"inputRef": "lo_custkey"}
              ],
              "op": "EQUALS"
            },
            "inputs": [
              {
                "condition": {
                  "operands": [
                    {"inputRef": "c_city"},
                    {"literals": {
                      "values": [
                        "UNITED KI1",
                        "UNITED KI5"
                      ],
                      "type": "VARCHAR"
                    }}
                  ],
                  "op": "IN"
                },
                "inputs": [{
                  "inputs": [{
                    "schema": "ssb-sf1-sortlineorder/csv/",
                    "inputs": [],
                    "operator": "EnumerableTableScan",
                    "table": "customer"
                  }],
                  "fields": [
                    {
                      "name": "c_custkey",
                      "expr": {"inputRef": "c_custkey"}
                    },
                    {
                      "name": "c_city",
                      "expr": {"inputRef": "c_city"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }],
                "operator": "EnumerableFilter"
              },
              {
                "inputs": [{
                  "condition": {
                    "operands": [
                      {"inputRef": "d_datekey"},
                      {"inputRef": "lo_orderdate"}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [
                    {
                      "condition": {
                        "operands": [
                          {
                            "operands": [
                              {"inputRef": "d_year"},
                              {"literal": {
                                "type": "INTEGER",
                                "value": 1992
                              }}
                            ],
                            "op": "GREATER_THAN_OR_EQUAL"
                          },
                          {
                            "operands": [
                              {"inputRef": "d_year"},
                              {"literal": {
                                "type": "INTEGER",
                                "value": 1997
                              }}
                            ],
                            "op": "LESS_THAN_OR_EQUAL"
                          }
                        ],
                        "op": "AND"
                      },
                      "inputs": [{
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "date"
                        }],
                        "fields": [
                          {
                            "name": "d_datekey",
                            "expr": {"inputRef": "d_datekey"}
                          },
                          {
                            "name": "d_year",
                            "expr": {"inputRef": "d_year"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }],
                      "operator": "EnumerableFilter"
                    },
                    {
                      "inputs": [{
                        "condition": {
                          "operands": [
                            {"inputRef": "s_suppkey"},
                            {"inputRef": "lo_suppkey"}
                          ],
                          "op": "EQUALS"
                        },
                        "inputs": [
                          {
                            "condition": {
                              "operands": [
                                {"inputRef": "s_city"},
                                {"literals": {
                                  "values": [
                                    "UNITED ST0",
                                    "UNITED ST9"
                                  ],
                                  "type": "VARCHAR"
                                }}
                              ],
                              "op": "IN"
                            },
                            "inputs": [{
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "supplier"
                              }],
                              "fields": [
                                {
                                  "name": "s_city",
                                  "expr": {"inputRef": "s_city"}
                                },
                                {
                                  "name": "s_suppkey",
                                  "expr": {"inputRef": "s_suppkey"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }],
                            "operator": "EnumerableFilter"
                          },
                          {
                            "inputs": [{
                              "schema": "ssb-sf1-sortlineorder/csv/",
                              "inputs": [],
                              "operator": "EnumerableTableScan",
                              "table": "lineorder"
                            }],
                            "fields": [
                              {
                                "name": "lo_custkey",
                                "expr": {"inputRef": "lo_custkey"}
                              },
                              {
                                "name": "lo_revenue",
                                "expr": {"inputRef": "lo_revenue"}
                              },
                              {
                                "name": "lo_suppkey",
                                "expr": {"inputRef": "lo_suppkey"}
                              },
                              {
                                "name": "lo_orderdate",
                                "expr": {"inputRef": "lo_orderdate"}
                              }
                            ],
                            "operator": "EnumerableProject"
                          }
                        ],
                        "joinType": "INNER",
                        "operator": "EnumerableHashJoin"
                      }],
                      "fields": [
                        {
                          "name": "lo_custkey",
                          "expr": {"inputRef": "lo_custkey"}
                        },
                        {
                          "name": "lo_revenue",
                          "expr": {"inputRef": "lo_revenue"}
                        },
                        {
                          "name": "lo_suppkey",
                          "expr": {"inputRef": "lo_suppkey"}
                        },
                        {
                          "name": "lo_orderdate",
                          "expr": {"inputRef": "lo_orderdate"}
                        },
                        {
                          "name": "s_city",
                          "expr": {"inputRef": "s_city"}
                        },
                        {
                          "name": "s_suppkey",
                          "expr": {"inputRef": "s_suppkey"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    }
                  ],
                  "joinType": "INNER",
                  "operator": "EnumerableHashJoin"
                }],
                "fields": [
                  {
                    "name": "lo_custkey",
                    "expr": {"inputRef": "lo_custkey"}
                  },
                  {
                    "name": "lo_revenue",
                    "expr": {"inputRef": "lo_revenue"}
                  },
                  {
                    "name": "lo_suppkey",
                    "expr": {"inputRef": "lo_suppkey"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "s_city",
                    "expr": {"inputRef": "s_city"}
                  },
                  {
                    "name": "s_suppkey",
                    "expr": {"inputRef": "s_suppkey"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  }
                ],
                "operator": "EnumerableProject"
              }
            ],
            "joinType": "INNER",
            "operator": "EnumerableHashJoin"
          }],
          "fields": [
            {
              "name": "c_city",
              "expr": {"inputRef": "c_city"}
            },
            {
              "name": "s_city",
              "expr": {"inputRef": "s_city"}
            },
            {
              "name": "d_year",
              "expr": {"inputRef": "d_year"}
            },
            {
              "name": "lo_revenue",
              "expr": {"inputRef": "lo_revenue"}
            }
          ],
          "operator": "EnumerableProject"
        }],
        "groupFields": [
          "c_city",
          "s_city",
          "d_year"
        ],
        "aggregations": [{
          "aggOutputField": "REVENUE",
          "aggInputField": "lo_revenue",
          "aggFunction": "SUM"
        }],
        "operator": "EnumerableAggregate"
      }],
      "sortFields": [
        {
          "field": "d_year",
          "direction": "ASCENDING"
        },
        {
          "field": "REVENUE",
          "direction": "DESCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 3.4：

  ```
  Query: ssb/original/3.4.sql
  Plan result:
  {
    "outputFields": [
      "c_city",
      "s_city",
      "d_year",
      "REVENUE"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "condition": {
              "operands": [
                {"inputRef": "c_custkey"},
                {"inputRef": "lo_custkey"}
              ],
              "op": "EQUALS"
            },
            "inputs": [
              {
                "condition": {
                  "operands": [
                    {"inputRef": "c_city"},
                    {"literals": {
                      "values": [
                        "UNITED KI1",
                        "UNITED KI5"
                      ],
                      "type": "VARCHAR"
                    }}
                  ],
                  "op": "IN"
                },
                "inputs": [{
                  "inputs": [{
                    "schema": "ssb-sf1-sortlineorder/csv/",
                    "inputs": [],
                    "operator": "EnumerableTableScan",
                    "table": "customer"
                  }],
                  "fields": [
                    {
                      "name": "c_custkey",
                      "expr": {"inputRef": "c_custkey"}
                    },
                    {
                      "name": "c_city",
                      "expr": {"inputRef": "c_city"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }],
                "operator": "EnumerableFilter"
              },
              {
                "inputs": [{
                  "condition": {
                    "operands": [
                      {"inputRef": "s_suppkey"},
                      {"inputRef": "lo_suppkey"}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [
                    {
                      "condition": {
                        "operands": [
                          {"inputRef": "s_city"},
                          {"literals": {
                            "values": [
                              "UNITED ST0",
                              "UNITED ST9"
                            ],
                            "type": "VARCHAR"
                          }}
                        ],
                        "op": "IN"
                      },
                      "inputs": [{
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "supplier"
                        }],
                        "fields": [
                          {
                            "name": "s_city",
                            "expr": {"inputRef": "s_city"}
                          },
                          {
                            "name": "s_suppkey",
                            "expr": {"inputRef": "s_suppkey"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }],
                      "operator": "EnumerableFilter"
                    },
                    {
                      "inputs": [{
                        "condition": {
                          "operands": [
                            {"inputRef": "d_datekey"},
                            {"inputRef": "lo_orderdate"}
                          ],
                          "op": "EQUALS"
                        },
                        "inputs": [
                          {
                            "condition": {
                              "operands": [
                                {"inputRef": "d_yearmonth"},
                                {"literal": {
                                  "type": "VARCHAR",
                                  "value": "Jan1992"
                                }}
                              ],
                              "op": "EQUALS"
                            },
                            "inputs": [{
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "date"
                              }],
                              "fields": [
                                {
                                  "name": "d_datekey",
                                  "expr": {"inputRef": "d_datekey"}
                                },
                                {
                                  "name": "d_year",
                                  "expr": {"inputRef": "d_year"}
                                },
                                {
                                  "name": "d_yearmonth",
                                  "expr": {"inputRef": "d_yearmonth"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }],
                            "operator": "EnumerableFilter"
                          },
                          {
                            "inputs": [{
                              "schema": "ssb-sf1-sortlineorder/csv/",
                              "inputs": [],
                              "operator": "EnumerableTableScan",
                              "table": "lineorder"
                            }],
                            "fields": [
                              {
                                "name": "lo_custkey",
                                "expr": {"inputRef": "lo_custkey"}
                              },
                              {
                                "name": "lo_revenue",
                                "expr": {"inputRef": "lo_revenue"}
                              },
                              {
                                "name": "lo_suppkey",
                                "expr": {"inputRef": "lo_suppkey"}
                              },
                              {
                                "name": "lo_orderdate",
                                "expr": {"inputRef": "lo_orderdate"}
                              }
                            ],
                            "operator": "EnumerableProject"
                          }
                        ],
                        "joinType": "INNER",
                        "operator": "EnumerableHashJoin"
                      }],
                      "fields": [
                        {
                          "name": "lo_custkey",
                          "expr": {"inputRef": "lo_custkey"}
                        },
                        {
                          "name": "lo_revenue",
                          "expr": {"inputRef": "lo_revenue"}
                        },
                        {
                          "name": "lo_suppkey",
                          "expr": {"inputRef": "lo_suppkey"}
                        },
                        {
                          "name": "lo_orderdate",
                          "expr": {"inputRef": "lo_orderdate"}
                        },
                        {
                          "name": "d_datekey",
                          "expr": {"inputRef": "d_datekey"}
                        },
                        {
                          "name": "d_year",
                          "expr": {"inputRef": "d_year"}
                        },
                        {
                          "name": "d_yearmonth",
                          "expr": {"inputRef": "d_yearmonth"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    }
                  ],
                  "joinType": "INNER",
                  "operator": "EnumerableHashJoin"
                }],
                "fields": [
                  {
                    "name": "lo_custkey",
                    "expr": {"inputRef": "lo_custkey"}
                  },
                  {
                    "name": "lo_revenue",
                    "expr": {"inputRef": "lo_revenue"}
                  },
                  {
                    "name": "lo_suppkey",
                    "expr": {"inputRef": "lo_suppkey"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  },
                  {
                    "name": "d_yearmonth",
                    "expr": {"inputRef": "d_yearmonth"}
                  },
                  {
                    "name": "s_city",
                    "expr": {"inputRef": "s_city"}
                  },
                  {
                    "name": "s_suppkey",
                    "expr": {"inputRef": "s_suppkey"}
                  }
                ],
                "operator": "EnumerableProject"
              }
            ],
            "joinType": "INNER",
            "operator": "EnumerableHashJoin"
          }],
          "fields": [
            {
              "name": "c_city",
              "expr": {"inputRef": "c_city"}
            },
            {
              "name": "s_city",
              "expr": {"inputRef": "s_city"}
            },
            {
              "name": "d_year",
              "expr": {"inputRef": "d_year"}
            },
            {
              "name": "lo_revenue",
              "expr": {"inputRef": "lo_revenue"}
            }
          ],
          "operator": "EnumerableProject"
        }],
        "groupFields": [
          "c_city",
          "s_city",
          "d_year"
        ],
        "aggregations": [{
          "aggOutputField": "REVENUE",
          "aggInputField": "lo_revenue",
          "aggFunction": "SUM"
        }],
        "operator": "EnumerableAggregate"
      }],
      "sortFields": [
        {
          "field": "d_year",
          "direction": "ASCENDING"
        },
        {
          "field": "REVENUE",
          "direction": "DESCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 4.1：

  ```
  Query: ssb/original/4.1.sql
  Plan result:
  {
    "outputFields": [
      "d_year",
      "c_nation",
      "PROFIT"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "condition": {
              "operands": [
                {"inputRef": "p_partkey"},
                {"inputRef": "lo_partkey"}
              ],
              "op": "EQUALS"
            },
            "inputs": [
              {
                "condition": {
                  "operands": [
                    {"inputRef": "p_mfgr"},
                    {"literals": {
                      "values": [
                        "MFGR#1",
                        "MFGR#2"
                      ],
                      "type": "VARCHAR"
                    }}
                  ],
                  "op": "IN"
                },
                "inputs": [{
                  "inputs": [{
                    "schema": "ssb-sf1-sortlineorder/csv/",
                    "inputs": [],
                    "operator": "EnumerableTableScan",
                    "table": "part"
                  }],
                  "fields": [
                    {
                      "name": "p_partkey",
                      "expr": {"inputRef": "p_partkey"}
                    },
                    {
                      "name": "p_mfgr",
                      "expr": {"inputRef": "p_mfgr"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }],
                "operator": "EnumerableFilter"
              },
              {
                "inputs": [{
                  "condition": {
                    "operands": [
                      {"inputRef": "c_custkey"},
                      {"inputRef": "lo_custkey"}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [
                    {
                      "condition": {
                        "operands": [
                          {"inputRef": "c_region"},
                          {"literal": {
                            "type": "VARCHAR",
                            "value": "AMERICA"
                          }}
                        ],
                        "op": "EQUALS"
                      },
                      "inputs": [{
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "customer"
                        }],
                        "fields": [
                          {
                            "name": "c_custkey",
                            "expr": {"inputRef": "c_custkey"}
                          },
                          {
                            "name": "c_nation",
                            "expr": {"inputRef": "c_nation"}
                          },
                          {
                            "name": "c_region",
                            "expr": {"inputRef": "c_region"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }],
                      "operator": "EnumerableFilter"
                    },
                    {
                      "inputs": [{
                        "condition": {
                          "operands": [
                            {"inputRef": "d_datekey"},
                            {"inputRef": "lo_orderdate"}
                          ],
                          "op": "EQUALS"
                        },
                        "inputs": [
                          {
                            "inputs": [{
                              "schema": "ssb-sf1-sortlineorder/csv/",
                              "inputs": [],
                              "operator": "EnumerableTableScan",
                              "table": "date"
                            }],
                            "fields": [
                              {
                                "name": "d_datekey",
                                "expr": {"inputRef": "d_datekey"}
                              },
                              {
                                "name": "d_year",
                                "expr": {"inputRef": "d_year"}
                              }
                            ],
                            "operator": "EnumerableProject"
                          },
                          {
                            "inputs": [{
                              "condition": {
                                "operands": [
                                  {"inputRef": "s_suppkey"},
                                  {"inputRef": "lo_suppkey"}
                                ],
                                "op": "EQUALS"
                              },
                              "inputs": [
                                {
                                  "condition": {
                                    "operands": [
                                      {"inputRef": "s_region"},
                                      {"literal": {
                                        "type": "VARCHAR",
                                        "value": "AMERICA"
                                      }}
                                    ],
                                    "op": "EQUALS"
                                  },
                                  "inputs": [{
                                    "inputs": [{
                                      "schema": "ssb-sf1-sortlineorder/csv/",
                                      "inputs": [],
                                      "operator": "EnumerableTableScan",
                                      "table": "supplier"
                                    }],
                                    "fields": [
                                      {
                                        "name": "s_suppkey",
                                        "expr": {"inputRef": "s_suppkey"}
                                      },
                                      {
                                        "name": "s_region",
                                        "expr": {"inputRef": "s_region"}
                                      }
                                    ],
                                    "operator": "EnumerableProject"
                                  }],
                                  "operator": "EnumerableFilter"
                                },
                                {
                                  "inputs": [{
                                    "schema": "ssb-sf1-sortlineorder/csv/",
                                    "inputs": [],
                                    "operator": "EnumerableTableScan",
                                    "table": "lineorder"
                                  }],
                                  "fields": [
                                    {
                                      "name": "lo_custkey",
                                      "expr": {"inputRef": "lo_custkey"}
                                    },
                                    {
                                      "name": "lo_partkey",
                                      "expr": {"inputRef": "lo_partkey"}
                                    },
                                    {
                                      "name": "lo_revenue",
                                      "expr": {"inputRef": "lo_revenue"}
                                    },
                                    {
                                      "name": "lo_suppkey",
                                      "expr": {"inputRef": "lo_suppkey"}
                                    },
                                    {
                                      "name": "lo_supplycost",
                                      "expr": {"inputRef": "lo_supplycost"}
                                    },
                                    {
                                      "name": "lo_orderdate",
                                      "expr": {"inputRef": "lo_orderdate"}
                                    }
                                  ],
                                  "operator": "EnumerableProject"
                                }
                              ],
                              "joinType": "INNER",
                              "operator": "EnumerableHashJoin"
                            }],
                            "fields": [
                              {
                                "name": "lo_custkey",
                                "expr": {"inputRef": "lo_custkey"}
                              },
                              {
                                "name": "lo_partkey",
                                "expr": {"inputRef": "lo_partkey"}
                              },
                              {
                                "name": "lo_revenue",
                                "expr": {"inputRef": "lo_revenue"}
                              },
                              {
                                "name": "lo_suppkey",
                                "expr": {"inputRef": "lo_suppkey"}
                              },
                              {
                                "name": "lo_supplycost",
                                "expr": {"inputRef": "lo_supplycost"}
                              },
                              {
                                "name": "lo_orderdate",
                                "expr": {"inputRef": "lo_orderdate"}
                              },
                              {
                                "name": "s_suppkey",
                                "expr": {"inputRef": "s_suppkey"}
                              },
                              {
                                "name": "s_region",
                                "expr": {"inputRef": "s_region"}
                              }
                            ],
                            "operator": "EnumerableProject"
                          }
                        ],
                        "joinType": "INNER",
                        "operator": "EnumerableHashJoin"
                      }],
                      "fields": [
                        {
                          "name": "lo_custkey",
                          "expr": {"inputRef": "lo_custkey"}
                        },
                        {
                          "name": "lo_partkey",
                          "expr": {"inputRef": "lo_partkey"}
                        },
                        {
                          "name": "lo_revenue",
                          "expr": {"inputRef": "lo_revenue"}
                        },
                        {
                          "name": "lo_suppkey",
                          "expr": {"inputRef": "lo_suppkey"}
                        },
                        {
                          "name": "lo_supplycost",
                          "expr": {"inputRef": "lo_supplycost"}
                        },
                        {
                          "name": "lo_orderdate",
                          "expr": {"inputRef": "lo_orderdate"}
                        },
                        {
                          "name": "s_suppkey",
                          "expr": {"inputRef": "s_suppkey"}
                        },
                        {
                          "name": "s_region",
                          "expr": {"inputRef": "s_region"}
                        },
                        {
                          "name": "d_datekey",
                          "expr": {"inputRef": "d_datekey"}
                        },
                        {
                          "name": "d_year",
                          "expr": {"inputRef": "d_year"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    }
                  ],
                  "joinType": "INNER",
                  "operator": "EnumerableHashJoin"
                }],
                "fields": [
                  {
                    "name": "lo_custkey",
                    "expr": {"inputRef": "lo_custkey"}
                  },
                  {
                    "name": "lo_partkey",
                    "expr": {"inputRef": "lo_partkey"}
                  },
                  {
                    "name": "lo_revenue",
                    "expr": {"inputRef": "lo_revenue"}
                  },
                  {
                    "name": "lo_suppkey",
                    "expr": {"inputRef": "lo_suppkey"}
                  },
                  {
                    "name": "lo_supplycost",
                    "expr": {"inputRef": "lo_supplycost"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "s_suppkey",
                    "expr": {"inputRef": "s_suppkey"}
                  },
                  {
                    "name": "s_region",
                    "expr": {"inputRef": "s_region"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  },
                  {
                    "name": "c_custkey",
                    "expr": {"inputRef": "c_custkey"}
                  },
                  {
                    "name": "c_nation",
                    "expr": {"inputRef": "c_nation"}
                  },
                  {
                    "name": "c_region",
                    "expr": {"inputRef": "c_region"}
                  }
                ],
                "operator": "EnumerableProject"
              }
            ],
            "joinType": "INNER",
            "operator": "EnumerableHashJoin"
          }],
          "fields": [
            {
              "name": "d_year",
              "expr": {"inputRef": "d_year"}
            },
            {
              "name": "c_nation",
              "expr": {"inputRef": "c_nation"}
            },
            {
              "name": "$f2",
              "expr": {
                "operands": [
                  {"inputRef": "lo_revenue"},
                  {"inputRef": "lo_supplycost"}
                ],
                "op": "MINUS"
              }
            }
          ],
          "operator": "EnumerableProject"
        }],
        "groupFields": [
          "d_year",
          "c_nation"
        ],
        "aggregations": [{
          "aggOutputField": "PROFIT",
          "aggInputField": "$f2",
          "aggFunction": "SUM"
        }],
        "operator": "EnumerableAggregate"
      }],
      "sortFields": [
        {
          "field": "d_year",
          "direction": "ASCENDING"
        },
        {
          "field": "c_nation",
          "direction": "ASCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 4.2：

  ```
  Query: ssb/original/4.2.sql
  Plan result:
  {
    "outputFields": [
      "d_year",
      "s_nation",
      "p_category",
      "PROFIT"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "condition": {
              "operands": [
                {"inputRef": "p_partkey"},
                {"inputRef": "lo_partkey"}
              ],
              "op": "EQUALS"
            },
            "inputs": [
              {
                "condition": {
                  "operands": [
                    {"inputRef": "p_mfgr"},
                    {"literals": {
                      "values": [
                        "MFGR#1",
                        "MFGR#2"
                      ],
                      "type": "VARCHAR"
                    }}
                  ],
                  "op": "IN"
                },
                "inputs": [{
                  "inputs": [{
                    "schema": "ssb-sf1-sortlineorder/csv/",
                    "inputs": [],
                    "operator": "EnumerableTableScan",
                    "table": "part"
                  }],
                  "fields": [
                    {
                      "name": "p_partkey",
                      "expr": {"inputRef": "p_partkey"}
                    },
                    {
                      "name": "p_category",
                      "expr": {"inputRef": "p_category"}
                    },
                    {
                      "name": "p_mfgr",
                      "expr": {"inputRef": "p_mfgr"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }],
                "operator": "EnumerableFilter"
              },
              {
                "inputs": [{
                  "condition": {
                    "operands": [
                      {"inputRef": "c_custkey"},
                      {"inputRef": "lo_custkey"}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [
                    {
                      "condition": {
                        "operands": [
                          {"inputRef": "c_region"},
                          {"literal": {
                            "type": "VARCHAR",
                            "value": "AMERICA"
                          }}
                        ],
                        "op": "EQUALS"
                      },
                      "inputs": [{
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "customer"
                        }],
                        "fields": [
                          {
                            "name": "c_custkey",
                            "expr": {"inputRef": "c_custkey"}
                          },
                          {
                            "name": "c_region",
                            "expr": {"inputRef": "c_region"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }],
                      "operator": "EnumerableFilter"
                    },
                    {
                      "inputs": [{
                        "condition": {
                          "operands": [
                            {"inputRef": "d_datekey"},
                            {"inputRef": "lo_orderdate"}
                          ],
                          "op": "EQUALS"
                        },
                        "inputs": [
                          {
                            "condition": {
                              "operands": [
                                {"inputRef": "d_year"},
                                {"literals": {
                                  "values": [
                                    1992,
                                    1993
                                  ],
                                  "type": "BIGINT"
                                }}
                              ],
                              "op": "IN"
                            },
                            "inputs": [{
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "date"
                              }],
                              "fields": [
                                {
                                  "name": "d_datekey",
                                  "expr": {"inputRef": "d_datekey"}
                                },
                                {
                                  "name": "d_year",
                                  "expr": {"inputRef": "d_year"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }],
                            "operator": "EnumerableFilter"
                          },
                          {
                            "inputs": [{
                              "condition": {
                                "operands": [
                                  {"inputRef": "s_suppkey"},
                                  {"inputRef": "lo_suppkey"}
                                ],
                                "op": "EQUALS"
                              },
                              "inputs": [
                                {
                                  "condition": {
                                    "operands": [
                                      {"inputRef": "s_region"},
                                      {"literal": {
                                        "type": "VARCHAR",
                                        "value": "AMERICA"
                                      }}
                                    ],
                                    "op": "EQUALS"
                                  },
                                  "inputs": [{
                                    "inputs": [{
                                      "schema": "ssb-sf1-sortlineorder/csv/",
                                      "inputs": [],
                                      "operator": "EnumerableTableScan",
                                      "table": "supplier"
                                    }],
                                    "fields": [
                                      {
                                        "name": "s_nation",
                                        "expr": {"inputRef": "s_nation"}
                                      },
                                      {
                                        "name": "s_suppkey",
                                        "expr": {"inputRef": "s_suppkey"}
                                      },
                                      {
                                        "name": "s_region",
                                        "expr": {"inputRef": "s_region"}
                                      }
                                    ],
                                    "operator": "EnumerableProject"
                                  }],
                                  "operator": "EnumerableFilter"
                                },
                                {
                                  "inputs": [{
                                    "schema": "ssb-sf1-sortlineorder/csv/",
                                    "inputs": [],
                                    "operator": "EnumerableTableScan",
                                    "table": "lineorder"
                                  }],
                                  "fields": [
                                    {
                                      "name": "lo_custkey",
                                      "expr": {"inputRef": "lo_custkey"}
                                    },
                                    {
                                      "name": "lo_partkey",
                                      "expr": {"inputRef": "lo_partkey"}
                                    },
                                    {
                                      "name": "lo_revenue",
                                      "expr": {"inputRef": "lo_revenue"}
                                    },
                                    {
                                      "name": "lo_suppkey",
                                      "expr": {"inputRef": "lo_suppkey"}
                                    },
                                    {
                                      "name": "lo_supplycost",
                                      "expr": {"inputRef": "lo_supplycost"}
                                    },
                                    {
                                      "name": "lo_orderdate",
                                      "expr": {"inputRef": "lo_orderdate"}
                                    }
                                  ],
                                  "operator": "EnumerableProject"
                                }
                              ],
                              "joinType": "INNER",
                              "operator": "EnumerableHashJoin"
                            }],
                            "fields": [
                              {
                                "name": "lo_custkey",
                                "expr": {"inputRef": "lo_custkey"}
                              },
                              {
                                "name": "lo_partkey",
                                "expr": {"inputRef": "lo_partkey"}
                              },
                              {
                                "name": "lo_revenue",
                                "expr": {"inputRef": "lo_revenue"}
                              },
                              {
                                "name": "lo_suppkey",
                                "expr": {"inputRef": "lo_suppkey"}
                              },
                              {
                                "name": "lo_supplycost",
                                "expr": {"inputRef": "lo_supplycost"}
                              },
                              {
                                "name": "lo_orderdate",
                                "expr": {"inputRef": "lo_orderdate"}
                              },
                              {
                                "name": "s_nation",
                                "expr": {"inputRef": "s_nation"}
                              },
                              {
                                "name": "s_suppkey",
                                "expr": {"inputRef": "s_suppkey"}
                              },
                              {
                                "name": "s_region",
                                "expr": {"inputRef": "s_region"}
                              }
                            ],
                            "operator": "EnumerableProject"
                          }
                        ],
                        "joinType": "INNER",
                        "operator": "EnumerableHashJoin"
                      }],
                      "fields": [
                        {
                          "name": "lo_custkey",
                          "expr": {"inputRef": "lo_custkey"}
                        },
                        {
                          "name": "lo_partkey",
                          "expr": {"inputRef": "lo_partkey"}
                        },
                        {
                          "name": "lo_revenue",
                          "expr": {"inputRef": "lo_revenue"}
                        },
                        {
                          "name": "lo_suppkey",
                          "expr": {"inputRef": "lo_suppkey"}
                        },
                        {
                          "name": "lo_supplycost",
                          "expr": {"inputRef": "lo_supplycost"}
                        },
                        {
                          "name": "lo_orderdate",
                          "expr": {"inputRef": "lo_orderdate"}
                        },
                        {
                          "name": "s_nation",
                          "expr": {"inputRef": "s_nation"}
                        },
                        {
                          "name": "s_suppkey",
                          "expr": {"inputRef": "s_suppkey"}
                        },
                        {
                          "name": "s_region",
                          "expr": {"inputRef": "s_region"}
                        },
                        {
                          "name": "d_datekey",
                          "expr": {"inputRef": "d_datekey"}
                        },
                        {
                          "name": "d_year",
                          "expr": {"inputRef": "d_year"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    }
                  ],
                  "joinType": "INNER",
                  "operator": "EnumerableHashJoin"
                }],
                "fields": [
                  {
                    "name": "lo_custkey",
                    "expr": {"inputRef": "lo_custkey"}
                  },
                  {
                    "name": "lo_partkey",
                    "expr": {"inputRef": "lo_partkey"}
                  },
                  {
                    "name": "lo_revenue",
                    "expr": {"inputRef": "lo_revenue"}
                  },
                  {
                    "name": "lo_suppkey",
                    "expr": {"inputRef": "lo_suppkey"}
                  },
                  {
                    "name": "lo_supplycost",
                    "expr": {"inputRef": "lo_supplycost"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "s_nation",
                    "expr": {"inputRef": "s_nation"}
                  },
                  {
                    "name": "s_suppkey",
                    "expr": {"inputRef": "s_suppkey"}
                  },
                  {
                    "name": "s_region",
                    "expr": {"inputRef": "s_region"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  },
                  {
                    "name": "c_custkey",
                    "expr": {"inputRef": "c_custkey"}
                  },
                  {
                    "name": "c_region",
                    "expr": {"inputRef": "c_region"}
                  }
                ],
                "operator": "EnumerableProject"
              }
            ],
            "joinType": "INNER",
            "operator": "EnumerableHashJoin"
          }],
          "fields": [
            {
              "name": "d_year",
              "expr": {"inputRef": "d_year"}
            },
            {
              "name": "s_nation",
              "expr": {"inputRef": "s_nation"}
            },
            {
              "name": "p_category",
              "expr": {"inputRef": "p_category"}
            },
            {
              "name": "$f3",
              "expr": {
                "operands": [
                  {"inputRef": "lo_revenue"},
                  {"inputRef": "lo_supplycost"}
                ],
                "op": "MINUS"
              }
            }
          ],
          "operator": "EnumerableProject"
        }],
        "groupFields": [
          "d_year",
          "s_nation",
          "p_category"
        ],
        "aggregations": [{
          "aggOutputField": "PROFIT",
          "aggInputField": "$f3",
          "aggFunction": "SUM"
        }],
        "operator": "EnumerableAggregate"
      }],
      "sortFields": [
        {
          "field": "d_year",
          "direction": "ASCENDING"
        },
        {
          "field": "s_nation",
          "direction": "ASCENDING"
        },
        {
          "field": "p_category",
          "direction": "ASCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 4.3：

  ```
  Query: ssb/original/4.3.sql
  Plan result:
  {
    "outputFields": [
      "d_year",
      "s_city",
      "p_brand1",
      "PROFIT"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "condition": {
              "operands": [
                {"inputRef": "p_partkey"},
                {"inputRef": "lo_partkey"}
              ],
              "op": "EQUALS"
            },
            "inputs": [
              {
                "condition": {
                  "operands": [
                    {"inputRef": "p_category"},
                    {"literal": {
                      "type": "VARCHAR",
                      "value": "MFGR#14"
                    }}
                  ],
                  "op": "EQUALS"
                },
                "inputs": [{
                  "inputs": [{
                    "schema": "ssb-sf1-sortlineorder/csv/",
                    "inputs": [],
                    "operator": "EnumerableTableScan",
                    "table": "part"
                  }],
                  "fields": [
                    {
                      "name": "p_partkey",
                      "expr": {"inputRef": "p_partkey"}
                    },
                    {
                      "name": "p_category",
                      "expr": {"inputRef": "p_category"}
                    },
                    {
                      "name": "p_brand1",
                      "expr": {"inputRef": "p_brand1"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }],
                "operator": "EnumerableFilter"
              },
              {
                "inputs": [{
                  "condition": {
                    "operands": [
                      {"inputRef": "c_custkey"},
                      {"inputRef": "lo_custkey"}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [
                    {
                      "condition": {
                        "operands": [
                          {"inputRef": "c_region"},
                          {"literal": {
                            "type": "VARCHAR",
                            "value": "AMERICA"
                          }}
                        ],
                        "op": "EQUALS"
                      },
                      "inputs": [{
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "customer"
                        }],
                        "fields": [
                          {
                            "name": "c_custkey",
                            "expr": {"inputRef": "c_custkey"}
                          },
                          {
                            "name": "c_region",
                            "expr": {"inputRef": "c_region"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }],
                      "operator": "EnumerableFilter"
                    },
                    {
                      "inputs": [{
                        "condition": {
                          "operands": [
                            {"inputRef": "d_datekey"},
                            {"inputRef": "lo_orderdate"}
                          ],
                          "op": "EQUALS"
                        },
                        "inputs": [
                          {
                            "condition": {
                              "operands": [
                                {"inputRef": "d_year"},
                                {"literals": {
                                  "values": [
                                    1992,
                                    1993
                                  ],
                                  "type": "BIGINT"
                                }}
                              ],
                              "op": "IN"
                            },
                            "inputs": [{
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "date"
                              }],
                              "fields": [
                                {
                                  "name": "d_datekey",
                                  "expr": {"inputRef": "d_datekey"}
                                },
                                {
                                  "name": "d_year",
                                  "expr": {"inputRef": "d_year"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }],
                            "operator": "EnumerableFilter"
                          },
                          {
                            "inputs": [{
                              "condition": {
                                "operands": [
                                  {"inputRef": "s_suppkey"},
                                  {"inputRef": "lo_suppkey"}
                                ],
                                "op": "EQUALS"
                              },
                              "inputs": [
                                {
                                  "condition": {
                                    "operands": [
                                      {"inputRef": "s_nation"},
                                      {"literal": {
                                        "type": "VARCHAR",
                                        "value": "UNITED STATES"
                                      }}
                                    ],
                                    "op": "EQUALS"
                                  },
                                  "inputs": [{
                                    "inputs": [{
                                      "schema": "ssb-sf1-sortlineorder/csv/",
                                      "inputs": [],
                                      "operator": "EnumerableTableScan",
                                      "table": "supplier"
                                    }],
                                    "fields": [
                                      {
                                        "name": "s_city",
                                        "expr": {"inputRef": "s_city"}
                                      },
                                      {
                                        "name": "s_nation",
                                        "expr": {"inputRef": "s_nation"}
                                      },
                                      {
                                        "name": "s_suppkey",
                                        "expr": {"inputRef": "s_suppkey"}
                                      }
                                    ],
                                    "operator": "EnumerableProject"
                                  }],
                                  "operator": "EnumerableFilter"
                                },
                                {
                                  "inputs": [{
                                    "schema": "ssb-sf1-sortlineorder/csv/",
                                    "inputs": [],
                                    "operator": "EnumerableTableScan",
                                    "table": "lineorder"
                                  }],
                                  "fields": [
                                    {
                                      "name": "lo_custkey",
                                      "expr": {"inputRef": "lo_custkey"}
                                    },
                                    {
                                      "name": "lo_partkey",
                                      "expr": {"inputRef": "lo_partkey"}
                                    },
                                    {
                                      "name": "lo_revenue",
                                      "expr": {"inputRef": "lo_revenue"}
                                    },
                                    {
                                      "name": "lo_suppkey",
                                      "expr": {"inputRef": "lo_suppkey"}
                                    },
                                    {
                                      "name": "lo_supplycost",
                                      "expr": {"inputRef": "lo_supplycost"}
                                    },
                                    {
                                      "name": "lo_orderdate",
                                      "expr": {"inputRef": "lo_orderdate"}
                                    }
                                  ],
                                  "operator": "EnumerableProject"
                                }
                              ],
                              "joinType": "INNER",
                              "operator": "EnumerableHashJoin"
                            }],
                            "fields": [
                              {
                                "name": "lo_custkey",
                                "expr": {"inputRef": "lo_custkey"}
                              },
                              {
                                "name": "lo_partkey",
                                "expr": {"inputRef": "lo_partkey"}
                              },
                              {
                                "name": "lo_revenue",
                                "expr": {"inputRef": "lo_revenue"}
                              },
                              {
                                "name": "lo_suppkey",
                                "expr": {"inputRef": "lo_suppkey"}
                              },
                              {
                                "name": "lo_supplycost",
                                "expr": {"inputRef": "lo_supplycost"}
                              },
                              {
                                "name": "lo_orderdate",
                                "expr": {"inputRef": "lo_orderdate"}
                              },
                              {
                                "name": "s_city",
                                "expr": {"inputRef": "s_city"}
                              },
                              {
                                "name": "s_nation",
                                "expr": {"inputRef": "s_nation"}
                              },
                              {
                                "name": "s_suppkey",
                                "expr": {"inputRef": "s_suppkey"}
                              }
                            ],
                            "operator": "EnumerableProject"
                          }
                        ],
                        "joinType": "INNER",
                        "operator": "EnumerableHashJoin"
                      }],
                      "fields": [
                        {
                          "name": "lo_custkey",
                          "expr": {"inputRef": "lo_custkey"}
                        },
                        {
                          "name": "lo_partkey",
                          "expr": {"inputRef": "lo_partkey"}
                        },
                        {
                          "name": "lo_revenue",
                          "expr": {"inputRef": "lo_revenue"}
                        },
                        {
                          "name": "lo_suppkey",
                          "expr": {"inputRef": "lo_suppkey"}
                        },
                        {
                          "name": "lo_supplycost",
                          "expr": {"inputRef": "lo_supplycost"}
                        },
                        {
                          "name": "lo_orderdate",
                          "expr": {"inputRef": "lo_orderdate"}
                        },
                        {
                          "name": "s_city",
                          "expr": {"inputRef": "s_city"}
                        },
                        {
                          "name": "s_nation",
                          "expr": {"inputRef": "s_nation"}
                        },
                        {
                          "name": "s_suppkey",
                          "expr": {"inputRef": "s_suppkey"}
                        },
                        {
                          "name": "d_datekey",
                          "expr": {"inputRef": "d_datekey"}
                        },
                        {
                          "name": "d_year",
                          "expr": {"inputRef": "d_year"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    }
                  ],
                  "joinType": "INNER",
                  "operator": "EnumerableHashJoin"
                }],
                "fields": [
                  {
                    "name": "lo_custkey",
                    "expr": {"inputRef": "lo_custkey"}
                  },
                  {
                    "name": "lo_partkey",
                    "expr": {"inputRef": "lo_partkey"}
                  },
                  {
                    "name": "lo_revenue",
                    "expr": {"inputRef": "lo_revenue"}
                  },
                  {
                    "name": "lo_suppkey",
                    "expr": {"inputRef": "lo_suppkey"}
                  },
                  {
                    "name": "lo_supplycost",
                    "expr": {"inputRef": "lo_supplycost"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "s_city",
                    "expr": {"inputRef": "s_city"}
                  },
                  {
                    "name": "s_nation",
                    "expr": {"inputRef": "s_nation"}
                  },
                  {
                    "name": "s_suppkey",
                    "expr": {"inputRef": "s_suppkey"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  },
                  {
                    "name": "d_year",
                    "expr": {"inputRef": "d_year"}
                  },
                  {
                    "name": "c_custkey",
                    "expr": {"inputRef": "c_custkey"}
                  },
                  {
                    "name": "c_region",
                    "expr": {"inputRef": "c_region"}
                  }
                ],
                "operator": "EnumerableProject"
              }
            ],
            "joinType": "INNER",
            "operator": "EnumerableHashJoin"
          }],
          "fields": [
            {
              "name": "d_year",
              "expr": {"inputRef": "d_year"}
            },
            {
              "name": "s_city",
              "expr": {"inputRef": "s_city"}
            },
            {
              "name": "p_brand1",
              "expr": {"inputRef": "p_brand1"}
            },
            {
              "name": "$f3",
              "expr": {
                "operands": [
                  {"inputRef": "lo_revenue"},
                  {"inputRef": "lo_supplycost"}
                ],
                "op": "MINUS"
              }
            }
          ],
          "operator": "EnumerableProject"
        }],
        "groupFields": [
          "d_year",
          "s_city",
          "p_brand1"
        ],
        "aggregations": [{
          "aggOutputField": "PROFIT",
          "aggInputField": "$f3",
          "aggFunction": "SUM"
        }],
        "operator": "EnumerableAggregate"
      }],
      "sortFields": [
        {
          "field": "d_year",
          "direction": "ASCENDING"
        },
        {
          "field": "s_city",
          "direction": "ASCENDING"
        },
        {
          "field": "p_brand1",
          "direction": "ASCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 4.4：

  ```
  
  ```

+ 1：

  ```
  
  ```

+ 2：

  ```
  
  ```

+ 3：

  ```
  
  ```

+ 4：

  ```
  Query: ssb/generated/4.sql
  Plan result:
  {
    "outputFields": [
      "EXPR$0",
      "D_YEARMONTHNUM",
      "P_BRAND1"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "inputs": [{
              "condition": {
                "operands": [
                  {"inputRef": "p_partkey"},
                  {"inputRef": "lo_partkey"}
                ],
                "op": "EQUALS"
              },
              "inputs": [
                {
                  "condition": {
                    "operands": [
                      {"inputRef": "p_brand1"},
                      {"literal": {
                        "type": "VARCHAR",
                        "value": "MFGR#5120"
                      }}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [{
                    "inputs": [{
                      "schema": "ssb-sf1-sortlineorder/csv/",
                      "inputs": [],
                      "operator": "EnumerableTableScan",
                      "table": "part"
                    }],
                    "fields": [
                      {
                        "name": "p_partkey",
                        "expr": {"inputRef": "p_partkey"}
                      },
                      {
                        "name": "p_brand1",
                        "expr": {"inputRef": "p_brand1"}
                      }
                    ],
                    "operator": "EnumerableProject"
                  }],
                  "operator": "EnumerableFilter"
                },
                {
                  "inputs": [{
                    "condition": {
                      "operands": [
                        {"inputRef": "d_datekey"},
                        {"inputRef": "lo_orderdate"}
                      ],
                      "op": "EQUALS"
                    },
                    "inputs": [
                      {
                        "inputs": [{
                          "schema": "ssb-sf1-sortlineorder/csv/",
                          "inputs": [],
                          "operator": "EnumerableTableScan",
                          "table": "date"
                        }],
                        "fields": [
                          {
                            "name": "d_yearmonthnum",
                            "expr": {"inputRef": "d_yearmonthnum"}
                          },
                          {
                            "name": "d_datekey",
                            "expr": {"inputRef": "d_datekey"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      },
                      {
                        "inputs": [{
                          "condition": {
                            "operands": [
                              {"inputRef": "s_suppkey"},
                              {"inputRef": "lo_suppkey"}
                            ],
                            "op": "EQUALS"
                          },
                          "inputs": [
                            {
                              "condition": {
                                "operands": [
                                  {"inputRef": "s_region"},
                                  {"literal": {
                                    "type": "VARCHAR",
                                    "value": "ASIA"
                                  }}
                                ],
                                "op": "EQUALS"
                              },
                              "inputs": [{
                                "inputs": [{
                                  "schema": "ssb-sf1-sortlineorder/csv/",
                                  "inputs": [],
                                  "operator": "EnumerableTableScan",
                                  "table": "supplier"
                                }],
                                "fields": [
                                  {
                                    "name": "s_suppkey",
                                    "expr": {"inputRef": "s_suppkey"}
                                  },
                                  {
                                    "name": "s_region",
                                    "expr": {"inputRef": "s_region"}
                                  }
                                ],
                                "operator": "EnumerableProject"
                              }],
                              "operator": "EnumerableFilter"
                            },
                            {
                              "condition": {
                                "operands": [
                                  {
                                    "operands": [
                                      {
                                        "operands": [
                                          {"inputRef": "lo_quantity"},
                                          {"literal": {
                                            "type": "INTEGER",
                                            "value": 17
                                          }}
                                        ],
                                        "op": "GREATER_THAN_OR_EQUAL"
                                      },
                                      {
                                        "operands": [
                                          {"inputRef": "lo_quantity"},
                                          {"literal": {
                                            "type": "INTEGER",
                                            "value": 27
                                          }}
                                        ],
                                        "op": "LESS_THAN_OR_EQUAL"
                                      }
                                    ],
                                    "op": "AND"
                                  },
                                  {
                                    "operands": [
                                      {
                                        "operands": [
                                          {"inputRef": "lo_orderdate"},
                                          {"literal": {
                                            "type": "INTEGER",
                                            "value": 19970101
                                          }}
                                        ],
                                        "op": "GREATER_THAN_OR_EQUAL"
                                      },
                                      {
                                        "operands": [
                                          {"inputRef": "lo_orderdate"},
                                          {"literal": {
                                            "type": "INTEGER",
                                            "value": 19971231
                                          }}
                                        ],
                                        "op": "LESS_THAN_OR_EQUAL"
                                      }
                                    ],
                                    "op": "AND"
                                  }
                                ],
                                "op": "AND"
                              },
                              "inputs": [{
                                "inputs": [{
                                  "schema": "ssb-sf1-sortlineorder/csv/",
                                  "inputs": [],
                                  "operator": "EnumerableTableScan",
                                  "table": "lineorder"
                                }],
                                "fields": [
                                  {
                                    "name": "lo_partkey",
                                    "expr": {"inputRef": "lo_partkey"}
                                  },
                                  {
                                    "name": "lo_revenue",
                                    "expr": {"inputRef": "lo_revenue"}
                                  },
                                  {
                                    "name": "lo_quantity",
                                    "expr": {"inputRef": "lo_quantity"}
                                  },
                                  {
                                    "name": "lo_suppkey",
                                    "expr": {"inputRef": "lo_suppkey"}
                                  },
                                  {
                                    "name": "lo_orderdate",
                                    "expr": {"inputRef": "lo_orderdate"}
                                  }
                                ],
                                "operator": "EnumerableProject"
                              }],
                              "operator": "EnumerableFilter"
                            }
                          ],
                          "joinType": "INNER",
                          "operator": "EnumerableHashJoin"
                        }],
                        "fields": [
                          {
                            "name": "lo_partkey",
                            "expr": {"inputRef": "lo_partkey"}
                          },
                          {
                            "name": "lo_revenue",
                            "expr": {"inputRef": "lo_revenue"}
                          },
                          {
                            "name": "lo_quantity",
                            "expr": {"inputRef": "lo_quantity"}
                          },
                          {
                            "name": "lo_suppkey",
                            "expr": {"inputRef": "lo_suppkey"}
                          },
                          {
                            "name": "lo_orderdate",
                            "expr": {"inputRef": "lo_orderdate"}
                          },
                          {
                            "name": "s_suppkey",
                            "expr": {"inputRef": "s_suppkey"}
                          },
                          {
                            "name": "s_region",
                            "expr": {"inputRef": "s_region"}
                          }
                        ],
                        "operator": "EnumerableProject"
                      }
                    ],
                    "joinType": "INNER",
                    "operator": "EnumerableHashJoin"
                  }],
                  "fields": [
                    {
                      "name": "lo_partkey",
                      "expr": {"inputRef": "lo_partkey"}
                    },
                    {
                      "name": "lo_revenue",
                      "expr": {"inputRef": "lo_revenue"}
                    },
                    {
                      "name": "lo_quantity",
                      "expr": {"inputRef": "lo_quantity"}
                    },
                    {
                      "name": "lo_suppkey",
                      "expr": {"inputRef": "lo_suppkey"}
                    },
                    {
                      "name": "lo_orderdate",
                      "expr": {"inputRef": "lo_orderdate"}
                    },
                    {
                      "name": "s_suppkey",
                      "expr": {"inputRef": "s_suppkey"}
                    },
                    {
                      "name": "s_region",
                      "expr": {"inputRef": "s_region"}
                    },
                    {
                      "name": "d_yearmonthnum",
                      "expr": {"inputRef": "d_yearmonthnum"}
                    },
                    {
                      "name": "d_datekey",
                      "expr": {"inputRef": "d_datekey"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }
              ],
              "joinType": "INNER",
              "operator": "EnumerableHashJoin"
            }],
            "fields": [
              {
                "name": "d_yearmonthnum",
                "expr": {"inputRef": "d_yearmonthnum"}
              },
              {
                "name": "p_brand1",
                "expr": {"inputRef": "p_brand1"}
              },
              {
                "name": "lo_revenue",
                "expr": {"inputRef": "lo_revenue"}
              }
            ],
            "operator": "EnumerableProject"
          }],
          "groupFields": [
            "d_yearmonthnum",
            "p_brand1"
          ],
          "aggregations": [{
            "aggOutputField": "EXPR$0",
            "aggInputField": "lo_revenue",
            "aggFunction": "SUM"
          }],
          "operator": "EnumerableAggregate"
        }],
        "fields": [
          {
            "name": "EXPR$0",
            "expr": {"inputRef": "EXPR$0"}
          },
          {
            "name": "D_YEARMONTHNUM",
            "expr": {"inputRef": "d_yearmonthnum"}
          },
          {
            "name": "P_BRAND1",
            "expr": {"inputRef": "p_brand1"}
          }
        ],
        "operator": "EnumerableProject"
      }],
      "sortFields": [
        {
          "field": "D_YEARMONTHNUM",
          "direction": "ASCENDING"
        },
        {
          "field": "P_BRAND1",
          "direction": "ASCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

+ 5：

  ```
  Query: ssb/generated/5.sql
  Plan result:
  {
    "outputFields": [
      "c_city",
      "s_city",
      "d_yearmonthnum",
      "REVENUE"
    ],
    "plan": {
      "inputs": [{
        "inputs": [{
          "inputs": [{
            "condition": {
              "operands": [
                {"inputRef": "c_custkey"},
                {"inputRef": "lo_custkey"}
              ],
              "op": "EQUALS"
            },
            "inputs": [
              {
                "condition": {
                  "operands": [
                    {"inputRef": "c_city"},
                    {"literals": {
                      "values": [
                        "UNITED ST3",
                        "UNITED ST6"
                      ],
                      "type": "VARCHAR"
                    }}
                  ],
                  "op": "IN"
                },
                "inputs": [{
                  "inputs": [{
                    "schema": "ssb-sf1-sortlineorder/csv/",
                    "inputs": [],
                    "operator": "EnumerableTableScan",
                    "table": "customer"
                  }],
                  "fields": [
                    {
                      "name": "c_custkey",
                      "expr": {"inputRef": "c_custkey"}
                    },
                    {
                      "name": "c_city",
                      "expr": {"inputRef": "c_city"}
                    }
                  ],
                  "operator": "EnumerableProject"
                }],
                "operator": "EnumerableFilter"
              },
              {
                "inputs": [{
                  "condition": {
                    "operands": [
                      {"inputRef": "d_datekey"},
                      {"inputRef": "lo_orderdate"}
                    ],
                    "op": "EQUALS"
                  },
                  "inputs": [
                    {
                      "inputs": [{
                        "schema": "ssb-sf1-sortlineorder/csv/",
                        "inputs": [],
                        "operator": "EnumerableTableScan",
                        "table": "date"
                      }],
                      "fields": [
                        {
                          "name": "d_yearmonthnum",
                          "expr": {"inputRef": "d_yearmonthnum"}
                        },
                        {
                          "name": "d_datekey",
                          "expr": {"inputRef": "d_datekey"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    },
                    {
                      "inputs": [{
                        "condition": {
                          "operands": [
                            {"inputRef": "s_suppkey"},
                            {"inputRef": "lo_suppkey"}
                          ],
                          "op": "EQUALS"
                        },
                        "inputs": [
                          {
                            "condition": {
                              "operands": [
                                {"inputRef": "s_city"},
                                {"literals": {
                                  "values": [
                                    "UNITED ST3",
                                    "UNITED ST6"
                                  ],
                                  "type": "VARCHAR"
                                }}
                              ],
                              "op": "IN"
                            },
                            "inputs": [{
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "supplier"
                              }],
                              "fields": [
                                {
                                  "name": "s_city",
                                  "expr": {"inputRef": "s_city"}
                                },
                                {
                                  "name": "s_suppkey",
                                  "expr": {"inputRef": "s_suppkey"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }],
                            "operator": "EnumerableFilter"
                          },
                          {
                            "condition": {
                              "operands": [
                                {
                                  "operands": [
                                    {
                                      "operands": [
                                        {"inputRef": "lo_quantity"},
                                        {"literal": {
                                          "type": "INTEGER",
                                          "value": 12
                                        }}
                                      ],
                                      "op": "GREATER_THAN_OR_EQUAL"
                                    },
                                    {
                                      "operands": [
                                        {"inputRef": "lo_quantity"},
                                        {"literal": {
                                          "type": "INTEGER",
                                          "value": 22
                                        }}
                                      ],
                                      "op": "LESS_THAN_OR_EQUAL"
                                    }
                                  ],
                                  "op": "AND"
                                },
                                {
                                  "operands": [
                                    {
                                      "operands": [
                                        {"inputRef": "lo_orderdate"},
                                        {"literal": {
                                          "type": "INTEGER",
                                          "value": 19930101
                                        }}
                                      ],
                                      "op": "GREATER_THAN_OR_EQUAL"
                                    },
                                    {
                                      "operands": [
                                        {"inputRef": "lo_orderdate"},
                                        {"literal": {
                                          "type": "INTEGER",
                                          "value": 19931231
                                        }}
                                      ],
                                      "op": "LESS_THAN_OR_EQUAL"
                                    }
                                  ],
                                  "op": "AND"
                                }
                              ],
                              "op": "AND"
                            },
                            "inputs": [{
                              "inputs": [{
                                "schema": "ssb-sf1-sortlineorder/csv/",
                                "inputs": [],
                                "operator": "EnumerableTableScan",
                                "table": "lineorder"
                              }],
                              "fields": [
                                {
                                  "name": "lo_custkey",
                                  "expr": {"inputRef": "lo_custkey"}
                                },
                                {
                                  "name": "lo_revenue",
                                  "expr": {"inputRef": "lo_revenue"}
                                },
                                {
                                  "name": "lo_quantity",
                                  "expr": {"inputRef": "lo_quantity"}
                                },
                                {
                                  "name": "lo_suppkey",
                                  "expr": {"inputRef": "lo_suppkey"}
                                },
                                {
                                  "name": "lo_orderdate",
                                  "expr": {"inputRef": "lo_orderdate"}
                                }
                              ],
                              "operator": "EnumerableProject"
                            }],
                            "operator": "EnumerableFilter"
                          }
                        ],
                        "joinType": "INNER",
                        "operator": "EnumerableHashJoin"
                      }],
                      "fields": [
                        {
                          "name": "lo_custkey",
                          "expr": {"inputRef": "lo_custkey"}
                        },
                        {
                          "name": "lo_revenue",
                          "expr": {"inputRef": "lo_revenue"}
                        },
                        {
                          "name": "lo_quantity",
                          "expr": {"inputRef": "lo_quantity"}
                        },
                        {
                          "name": "lo_suppkey",
                          "expr": {"inputRef": "lo_suppkey"}
                        },
                        {
                          "name": "lo_orderdate",
                          "expr": {"inputRef": "lo_orderdate"}
                        },
                        {
                          "name": "s_city",
                          "expr": {"inputRef": "s_city"}
                        },
                        {
                          "name": "s_suppkey",
                          "expr": {"inputRef": "s_suppkey"}
                        }
                      ],
                      "operator": "EnumerableProject"
                    }
                  ],
                  "joinType": "INNER",
                  "operator": "EnumerableHashJoin"
                }],
                "fields": [
                  {
                    "name": "lo_custkey",
                    "expr": {"inputRef": "lo_custkey"}
                  },
                  {
                    "name": "lo_revenue",
                    "expr": {"inputRef": "lo_revenue"}
                  },
                  {
                    "name": "lo_quantity",
                    "expr": {"inputRef": "lo_quantity"}
                  },
                  {
                    "name": "lo_suppkey",
                    "expr": {"inputRef": "lo_suppkey"}
                  },
                  {
                    "name": "lo_orderdate",
                    "expr": {"inputRef": "lo_orderdate"}
                  },
                  {
                    "name": "s_city",
                    "expr": {"inputRef": "s_city"}
                  },
                  {
                    "name": "s_suppkey",
                    "expr": {"inputRef": "s_suppkey"}
                  },
                  {
                    "name": "d_yearmonthnum",
                    "expr": {"inputRef": "d_yearmonthnum"}
                  },
                  {
                    "name": "d_datekey",
                    "expr": {"inputRef": "d_datekey"}
                  }
                ],
                "operator": "EnumerableProject"
              }
            ],
            "joinType": "INNER",
            "operator": "EnumerableHashJoin"
          }],
          "fields": [
            {
              "name": "c_city",
              "expr": {"inputRef": "c_city"}
            },
            {
              "name": "s_city",
              "expr": {"inputRef": "s_city"}
            },
            {
              "name": "d_yearmonthnum",
              "expr": {"inputRef": "d_yearmonthnum"}
            },
            {
              "name": "lo_revenue",
              "expr": {"inputRef": "lo_revenue"}
            }
          ],
          "operator": "EnumerableProject"
        }],
        "groupFields": [
          "c_city",
          "s_city",
          "d_yearmonthnum"
        ],
        "aggregations": [{
          "aggOutputField": "REVENUE",
          "aggInputField": "lo_revenue",
          "aggFunction": "SUM"
        }],
        "operator": "EnumerableAggregate"
      }],
      "sortFields": [
        {
          "field": "d_yearmonthnum",
          "direction": "ASCENDING"
        },
        {
          "field": "REVENUE",
          "direction": "DESCENDING"
        }
      ],
      "operator": "EnumerableSort"
    }
  }
  ```

  