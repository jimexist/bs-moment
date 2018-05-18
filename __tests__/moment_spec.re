open Jest;

open MomentRe;

let isJsDateValid: Js.Date.t => bool = [%bs.raw
  {|
  function(date) {
    return (date instanceof Date && !isNaN(date.valueOf())) ? true : false;
  }
|}
];

/* note that this is an interops test, not tests for moment.js itself, i.e. test comprehensiveness is not the goal */
let () =
  describe(
    "moment",
    ExpectJs.(
      () => {
        test(
          "#clone",
          () => expect(moment("2017-01-01") |> Moment.clone |> Moment.isValid) |> toBe(true)
        );
        test(
          "#mutableSubtract",
          () =>
            expect(
              Moment.isSame(
                moment("2016-01-01"),
                {
                  let original = moment("2017-01-01");
                  Moment.mutableSubtract(original, duration(1, `years));
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#subtract",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01"),
                moment("2017-01-04")
                |> Moment.subtract(~duration=duration(1, `days))
                |> Moment.subtract(~duration=duration(2, `days))
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableAdd",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-04"),
                {
                  let original = moment("2017-01-01");
                  Moment.mutableAdd(original, duration(3, `days));
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#add",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-04"),
                moment("2017-01-01")
                |> Moment.add(~duration=duration(1, `days))
                |> Moment.add(~duration=duration(2, `days))
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetMillisecond",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01 02:25:05.100"),
                {
                  let original = moment("2017-01-01 02:25:05.000");
                  Moment.mutableSetMillisecond(original, 100);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setMillisecond",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01 02:25:05.100"),
                moment("2017-01-01 02:25:05.000")
                |> Moment.setMillisecond(200)
                |> Moment.setMillisecond(100)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetSecond",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01 02:25:30.100"),
                {
                  let original = moment("2017-01-01 02:25:05.100");
                  Moment.mutableSetSecond(original, 30);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setSecond",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01 02:25:30.100"),
                moment("2017-01-01 02:25:05.100")
                |> Moment.setSecond(20)
                |> Moment.setSecond(30)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetMinute",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01 02:25:30.100"),
                {
                  let original = moment("2017-01-01 02:20:30.100");
                  Moment.mutableSetMinute(original, 25);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setMinute",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01 02:25:30.100"),
                moment("2017-01-01 02:20:30.100")
                |> Moment.setMinute(30)
                |> Moment.setMinute(25)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetHour",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01 00:25:05.000"),
                {
                  let original = moment("2017-01-01 02:25:05.000");
                  Moment.mutableSetHour(original, 0);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setHour",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-01 00:25:05.000"),
                moment("2017-01-01 06:25:05.000")
                |> Moment.setHour(2)
                |> Moment.setHour(0)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetDate",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-04"),
                {
                  let original = moment("2017-01-01");
                  Moment.mutableSetDate(original, 4);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setDate",
          () =>
            expect(
              Moment.isSame(
                moment("2017-01-04"),
                moment("2017-01-01")
                |> Moment.setDate(2)
                |> Moment.setDate(4)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetDay",
          () =>
            expect(
              Moment.isSame(
                moment("2018-05-01"),
                {
                  let original = moment("2018-05-05");
                  Moment.mutableSetDay(original, 2);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setDay",
          () =>
            expect(
              Moment.isSame(
                moment("2018-05-01"),
                moment("2018-05-05")
                |> Moment.setDay(3)
                |> Moment.setDay(2)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetWeekday",
          () =>
            expect(
              Moment.isSame(
                moment("2018-05-01"),
                {
                  let original = moment("2018-05-05");
                  Moment.mutableSetWeekday(original, 2);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setWeekday",
          () =>
            expect(
              Moment.isSame(
                moment("2018-05-01"),
                moment("2018-05-05")
                |> Moment.setWeekday(3)
                |> Moment.setWeekday(2)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetIsoWeekday",
          () =>
            expect(
              Moment.isSame(
                moment("2018-05-01"),
                {
                  let original = moment("2018-05-05");
                  Moment.mutableSetIsoWeekday(original, 2);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setIsoWeekday",
          () =>
            expect(
              Moment.isSame(
                moment("2018-05-01"),
                moment("2018-05-05")
                |> Moment.setIsoWeekday(3)
                |> Moment.setIsoWeekday(2)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetDayOfYear",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-01"),
                {
                  let original = moment("2018-01-05");
                  Moment.mutableSetDayOfYear(original, 1);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setDayOfYear",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-01"),
                moment("2018-01-05")
                |> Moment.setDayOfYear(3)
                |> Moment.setDayOfYear(1)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetWeek",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-17"),
                {
                  let original = moment("2018-01-03");
                  Moment.mutableSetWeek(original, 3);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setWeek",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-17"),
                moment("2018-01-03")
                |> Moment.setWeek(5)
                |> Moment.setWeek(3)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetIsoWeek",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-17"),
                {
                  let original = moment("2018-01-03");
                  Moment.mutableSetIsoWeek(original, 3);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setIsoWeek",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-17"),
                moment("2018-01-03")
                |> Moment.setIsoWeek(5)
                |> Moment.setIsoWeek(3)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetMonth",
          () =>
            expect(
              Moment.isSame(
                moment("2017-04-01"),
                {
                  let original = moment("2017-01-01");
                  Moment.mutableSetMonth(original, 3);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setMonth",
          () =>
            expect(
              Moment.isSame(
                moment("2017-04-01"),
                moment("2017-01-01")
                |> Moment.setMonth(2)
                |> Moment.setMonth(3)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetQuarter",
          () =>
            expect(
              Moment.isSame(
                moment("2013-04-01T00:00:00.000"),
                {
                  let original = moment("2013-01-01T00:00:00.000");
                  Moment.mutableSetQuarter(original, 2);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setQuarter",
          () =>
            expect(
              Moment.isSame(
                moment("2013-04-01T00:00:00.000"),
                moment("2013-01-01T00:00:00.000")
                |> Moment.setQuarter(4)
                |> Moment.setQuarter(2)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetYear",
          () =>
            expect(
              Moment.isSame(
                moment("2019-01-01"),
                {
                  let original = moment("2017-01-01");
                  Moment.mutableSetYear(original, 2019);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setYear",
          () =>
            expect(
              Moment.isSame(
                moment("2019-01-01"),
                moment("2017-01-01")
                |> Moment.setYear(2018)
                |> Moment.setYear(2019)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetWeekYear",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-05"),
                {
                  let original = moment("2019-01-04");
                  Moment.mutableSetWeekYear(original, 2018);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setWeekYear",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-05"),
                moment("2019-01-04")
                |> Moment.setWeekYear(2020)
                |> Moment.setWeekYear(2018)
              )
            )
            |> toBe(true)
        );
        test(
          "#mutableSetIsoWeekYear",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-05"),
                {
                  let original = moment("2019-01-04");
                  Moment.mutableSetIsoWeekYear(original, 2018);
                  original
                }
              )
            )
            |> toBe(true)
        );
        test(
          "#setIsoWeekYear",
          () =>
            expect(
              Moment.isSame(
                moment("2018-01-05"),
                moment("2019-01-04")
                |> Moment.setIsoWeekYear(2020)
                |> Moment.setIsoWeekYear(2018)
              )
            )
            |> toBe(true)
        );
        test("#isValid", () => expect(moment("2017-01-01") |> Moment.isValid) |> toBe(true));
        test("not #isValid", () => expect(moment("") |> Moment.isValid) |> toBe(false));
        test("#isDST", () => expect(moment("2016-01-01T00:00:00") |> Moment.isDST) |> toBe(false));
        test("leap year", () => expect(moment("2016-01-01") |> Moment.isLeapYear) |> toBe(true));
        test(
          "not leap year",
          () => expect(moment("1900-01-01") |> Moment.isLeapYear) |> toBe(false)
        );
        test(
          "instantiation",
          () => expect(Moment.isSame(moment("2017-04-01"), moment("2017-04-01"))) |> toBe(true)
        );
        test(
          "instantiation with format",
          () => expect(Moment.isSame(moment("2017-04-01"), moment("2017-04-01"))) |> toBe(true)
        );
        test(
          "instantiation with date",
          () =>
            expect(
              Moment.isSame(
                momentWithDate(Js.Date.fromString("6 Mar 2017 21:22:23 GMT")),
                moment("6 Mar 2017 21:22:23 GMT")
              )
            )
            |> toBe(true)
        );
        test(
          "instantiation momentWithTimestampMS (float)",
          () =>
            expect(
              Moment.isSame(
                moment("2017-06-12T18:30:00+02:00"),
                momentWithTimestampMS(Int64.of_string("1497285000000") |> Int64.to_float)
              )
            )
            |> toBe(true)
        );
        test(
          "instantiation momentWithUnix (int)",
          () =>
            expect(Moment.isSame(moment("6 Mar 2017 21:22:23 GMT"), momentWithUnix(1488835343)))
            |> toBe(true)
        );
        test(".now", () => expect(momentNow() |> Moment.isValid) |> toBe(true));
        test(
          "#isSame",
          () => expect(Moment.isSame(moment("2016-01-01"), moment("2016-01-01"))) |> toBe(true)
        );
        test(
          "#isBefore",
          () => expect(Moment.isBefore(moment("2016-01-01"), moment("2016-01-02"))) |> toBe(true)
        );
        test(
          "#isSameOrBefore",
          () =>
            expect(Moment.isSameOrBefore(moment("2016-01-01"), moment("2016-01-02"))) |> toBe(true)
        );
        test(
          "#isAfter",
          () => expect(Moment.isAfter(moment("2016-01-02"), moment("2016-01-01"))) |> toBe(true)
        );
        test(
          "#isSameOrAfter",
          () =>
            expect(Moment.isSameOrAfter(moment("2016-01-02"), moment("2016-01-01"))) |> toBe(true)
        );
        test(
          "#isBetween",
          () =>
            expect(
              Moment.isBetween(moment("2016-01-02"), moment("2016-01-01"), moment("2016-01-03"))
            )
            |> toBe(true)
        );
        test(
          "#format",
          () => expect(moment("2016-01-01") |> Moment.format("YYYY-MM-DD")) |> toBe("2016-01-01")
        );
        test /* TODO: test this time-zone independently */(
          "#defaultFormat",
          () =>
            expect(moment("2016-01-01") |> Moment.defaultFormat) |> toContainString("2016-01-01")
        );
        test(
          "#utc",
          () =>
            expect(momentNow() |> MomentRe.Moment.utc("2018-01-22") |> Moment.isValid) |> toBe(true)
        );
        test(
          "#defaultUtc",
          () => expect(momentNow() |> MomentRe.Moment.defaultUtc |> Moment.isValid) |> toBe(true)
        );
        test (
          "#locale",
          () =>
            expect(moment("2018-01-01 00:00:00Z") |> Moment.locale("da_DK") |> Moment.format("MMMM Do YYYY")) |> toBe("januar 1. 2018")
        );
        test(
          "#valueOf", /* TODO: float? */
          () =>
            expect(moment("2016-01-01 00:00:00Z") |> Moment.valueOf) |> toBeCloseTo(1451606400000.)
        );
        test(
          "#toJSON",
          () => expect(moment("2016-01-01") |> Moment.toJSON) |> toContainString("000Z")
        );
        test(
          "#toDate",
          () => expect(isJsDateValid(moment("2016-01-01") |> Moment.toDate)) |> toBe(true)
        );
        test(
          "#toUnix",
          () => expect(moment("6 Mar 2017 21:22:23 GMT") |> Moment.toUnix) |> toBe(1488835343)
        );
        test(
          "#get",
          () => expect(moment("2017-01-02 03:04:05.678") |> Moment.get(`day)) |> toBe(1)
        );
        test(
          "#second",
          () => expect(moment("2017-01-02 03:04:05.678") |> Moment.second) |> toBe(5)
        );
        test(
          "#minute",
          () => expect(moment("2017-01-02 03:04:05.678") |> Moment.minute) |> toBe(4)
        );
        test("#hour", () => expect(moment("2017-01-02 03:04:05.678") |> Moment.hour) |> toBe(3));
        test("#day", () => expect(moment("2017-01-02 03:04:05.678") |> Moment.day) |> toBe(1));
        test("#week", () => expect(moment("2017-01-02 03:04:05.678") |> Moment.week) |> toBe(1));
        test("#month", () => expect(moment("2017-01-02 03:04:05.678") |> Moment.month) |> toBe(0));
        test("#year", () => expect(moment("2017-01-02 03:04:05.678") |> Moment.year) |> toBe(2017));
        test("#weekday", () => expect(moment("2017-01-02 03:04:05.678") |> Moment.weekday) |> toBe(1));
      }
    )
  );

let () =
  describe(
    "moment duration",
    ExpectJs.(
      () => {
        test("get duration", () => expect(duration(2, `days)) |> toBeTruthy);
        test("get duration millis", () => expect(durationMillis(2)) |> toBeTruthy);
        test(
          "get duration format",
          () => expect(durationFormat("P2D") |> Duration.toJSON) |> toBe("P2D")
        );
        test(
          "#milliseconds",
          () => expect(duration(2, `milliseconds) |> Duration.milliseconds) |> toBe(2)
        );
        test("#seconds", () => expect(duration(2, `seconds) |> Duration.seconds) |> toBe(2));
        test("#asSeconds", () => expect(duration(2, `seconds) |> Duration.asSeconds) |> toBe(2.));
        test("#minutes", () => expect(duration(2, `minutes) |> Duration.minutes) |> toBe(2));
        test("#asMinutes", () => expect(duration(2, `minutes) |> Duration.asMinutes) |> toBe(2.));
        test("#hours", () => expect(duration(2, `hours) |> Duration.hours) |> toBe(2));
        test("#asHours", () => expect(duration(2, `hours) |> Duration.asHours) |> toBe(2.));
        test("#days", () => expect(duration(2, `days) |> Duration.days) |> toBe(2));
        test("#asDays", () => expect(duration(2, `days) |> Duration.asDays) |> toBe(2.));
        test("#weeks", () => expect(duration(2, `weeks) |> Duration.weeks) |> toBe(2));
        test("#asWeeks", () => expect(duration(2, `weeks) |> Duration.asWeeks) |> toBe(2.));
        test("#months", () => expect(duration(2, `months) |> Duration.months) |> toBe(2));
        test("#asMonths", () => expect(duration(2, `months) |> Duration.asMonths) |> toBe(2.));
        test("#years", () => expect(duration(2, `years) |> Duration.years) |> toBe(2));
        test("#asYears", () => expect(duration(2, `years) |> Duration.asYears) |> toBe(2.));
        test("#as", () => expect(duration(2, `days) |> Duration.asUnitOfTime(`days)) |> toBe(2.));
        test("#toJSON", () => expect(duration(2, `days) |> Duration.toJSON) |> toBe("P2D"));
        test("#humanize", () => expect(duration(2, `days) |> Duration.humanize) |> toBe("2 days"))
      }
    )
  );

let () =
  describe(
    "moment diff",
    ExpectJs.(
      () => {
        test(
          "should return correct difference of moments in days",
          () => expect(diff(moment("2017-01-02"), moment("2017-01-01"), `days)) |> toBe(1.)
        );
        test(
          "should return correct difference of moments in hours",
          () =>
            expect(
              diff(moment("2017-01-01 02:00:00.000"), moment("2017-01-01 00:00:00.000"), `hours)
            )
            |> toBe(2.)
        );
        test(
          "should be able to handle negative difference of moments",
          () =>
            expect(
              diff(moment("2017-01-01 00:00:00.000"), moment("2017-01-01 02:00:00.000"), `hours)
            )
            |> toBe((-2.))
        );
        test(
          "should return correct difference of moments in hours",
          () =>
            expect(
              diff(moment("2017-01-01 00:25:05.000"), moment("2017-01-01 00:00:00.000"), `minutes)
            )
            |> toBe(25.)
        )
      }
    )
  );
