open Jest;

open MomentRe;

/* note that this is an interops test, not tests for moment.js itself, i.e. test comprehensiveness is not the goal */
let () =
  describe
    "moment"
    ExpectJs.(
      fun () => {
        test
          "#clone"
          (fun () => expect (moment "2017-01-01" |> Moment.clone |> Moment.isValid) |> toBe true);
        test
          "#mutableAdd"
          (
            fun () =>
              expect (
                Moment.isSame
                  (moment "2017-01-04")
                  {
                    let original = moment "2017-01-01";
                    Moment.mutableAdd original (duration 3 `days);
                    original
                  }
              ) |>
              toBe true
          );
        test
          "#add"
          (
            fun () =>
              expect (
                Moment.isSame
                  (moment "2017-01-04")
                  (
                    moment "2017-01-01" |> Moment.add duration::(duration 1 `days) |>
                    Moment.add duration::(duration 2 `days)
                  )
              ) |>
              toBe true
          );
        test "#isValid" (fun () => expect (moment "2017-01-01" |> Moment.isValid) |> toBe true);
        test "not #isValid" (fun () => expect (moment "" |> Moment.isValid) |> toBe false);
        test
          "#isDST" (fun () => expect (moment "2016-01-01T00:00:00" |> Moment.isDST) |> toBe false);
        test
          "leap year" (fun () => expect (moment "2016-01-01" |> Moment.isLeapYear) |> toBe true);
        test
          "not leap year"
          (fun () => expect (moment "1900-01-01" |> Moment.isLeapYear) |> toBe false);
        test
          "instantiation"
          (
            fun () =>
              expect (Moment.isSame (moment "2017-04-01") (moment "2017-04-01")) |> toBe true
          );
        test
          "instantiation with format"
          (
            fun () =>
              expect (Moment.isSame (moment "2017-04-01") (moment "2017-04-01")) |> toBe true
          );
        test ".now" (fun () => expect (momentNow () |> Moment.isValid) |> toBe true);
        test
          "#isSame"
          (
            fun () =>
              expect (Moment.isSame (moment "2016-01-01") (moment "2016-01-01")) |> toBe true
          );
        test
          "#isBefore"
          (
            fun () =>
              expect (Moment.isBefore (moment "2016-01-01") (moment "2016-01-02")) |> toBe true
          );
        test
          "#isSameOrBefore"
          (
            fun () =>
              expect (Moment.isSameOrBefore (moment "2016-01-01") (moment "2016-01-02")) |>
              toBe true
          );
        test
          "#isAfter"
          (
            fun () =>
              expect (Moment.isAfter (moment "2016-01-02") (moment "2016-01-01")) |> toBe true
          );
        test
          "#isSameOrAfter"
          (
            fun () =>
              expect (Moment.isSameOrAfter (moment "2016-01-02") (moment "2016-01-01")) |>
              toBe true
          );
        test
          "#isBetween"
          (
            fun () =>
              expect (
                Moment.isBetween (moment "2016-01-02") (moment "2016-01-01") (moment "2016-01-03")
              ) |>
              toBe true
          );
        test
          "#format"
          (
            fun () =>
              expect (moment "2016-01-01" |> Moment.format "YYYY-MM-DD") |> toBe "2016-01-01"
          );
        test /* TODO: test this time-zone independently */
          "#defaultFormat"
          (
            fun () =>
              expect (moment "2016-01-01" |> Moment.defaultFormat) |> toContainString "2016-01-01"
          );
        test
          "#valueOf" /* TODO: float? */
          (
            fun () =>
              expect (moment "2016-01-01 00:00:00Z" |> Moment.valueOf) |>
              toBeCloseTo 1451606400000.
          );
        test
          "#toJSON"
          (fun () => expect (moment "2016-01-01" |> Moment.toJSON) |> toContainString "000Z");
        test
          "#get"
          (fun () => expect (moment "2017-01-02 03:04:05.678" |> Moment.get `day) |> toBe 1);
        test
          "#second"
          (fun () => expect (moment "2017-01-02 03:04:05.678" |> Moment.second) |> toBe 5);
        test
          "#minute"
          (fun () => expect (moment "2017-01-02 03:04:05.678" |> Moment.minute) |> toBe 4);
        test
          "#hour" (fun () => expect (moment "2017-01-02 03:04:05.678" |> Moment.hour) |> toBe 3);
        test "#day" (fun () => expect (moment "2017-01-02 03:04:05.678" |> Moment.day) |> toBe 1);
        test
          "#week" (fun () => expect (moment "2017-01-02 03:04:05.678" |> Moment.week) |> toBe 1);
        test
          "#month" (fun () => expect (moment "2017-01-02 03:04:05.678" |> Moment.month) |> toBe 0);
        test
          "#year" (fun () => expect (moment "2017-01-02 03:04:05.678" |> Moment.year) |> toBe 2017)
      }
    );

let () =
  describe
    "moment duration"
    ExpectJs.(
      fun () => {
        test "get duration" (fun () => expect (duration 2 `days) |> toBeTruthy);
        test "get duration millis" (fun () => expect (durationMillis 2) |> toBeTruthy);
        test
          "get duration format"
          (fun () => expect (durationFormat "P2D" |> Duration.toJSON) |> toBe "P2D");
        test
          "#milliseconds"
          (fun () => expect (duration 2 `milliseconds |> Duration.milliseconds) |> toBe 2);
        test "#seconds" (fun () => expect (duration 2 `seconds |> Duration.seconds) |> toBe 2);
        test
          "#asSeconds" (fun () => expect (duration 2 `seconds |> Duration.asSeconds) |> toBe 2.);
        test "#minutes" (fun () => expect (duration 2 `minutes |> Duration.minutes) |> toBe 2);
        test
          "#asMinutes" (fun () => expect (duration 2 `minutes |> Duration.asMinutes) |> toBe 2.);
        test "#hours" (fun () => expect (duration 2 `hours |> Duration.hours) |> toBe 2);
        test "#asHours" (fun () => expect (duration 2 `hours |> Duration.asHours) |> toBe 2.);
        test "#days" (fun () => expect (duration 2 `days |> Duration.days) |> toBe 2);
        test "#asDays" (fun () => expect (duration 2 `days |> Duration.asDays) |> toBe 2.);
        test "#weeks" (fun () => expect (duration 2 `weeks |> Duration.weeks) |> toBe 2);
        test "#asWeeks" (fun () => expect (duration 2 `weeks |> Duration.asWeeks) |> toBe 2.);
        test "#months" (fun () => expect (duration 2 `months |> Duration.months) |> toBe 2);
        test "#asMonths" (fun () => expect (duration 2 `months |> Duration.asMonths) |> toBe 2.);
        test "#years" (fun () => expect (duration 2 `years |> Duration.years) |> toBe 2);
        test "#asYears" (fun () => expect (duration 2 `years |> Duration.asYears) |> toBe 2.);
        test "#as" (fun () => expect (duration 2 `days |> Duration.asUnitOfTime `days) |> toBe 2.);
        test "#toJSON" (fun () => expect (duration 2 `days |> Duration.toJSON) |> toBe "P2D");
        test
          "#humanize" (fun () => expect (duration 2 `days |> Duration.humanize) |> toBe "2 days")
      }
    );
